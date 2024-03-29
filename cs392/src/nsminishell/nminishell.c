// #include <stdio.h>
#define _POSIX_C_SOURCE 200809L
#define _XOPEN_SOURCE 500
#include <stdlib.h>
#include <stdio.h>
#include <term.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>
#include "list.h"


void printMessage(){
	attron(COLOR_PAIR(1));
	char cwd[1024];
	memset(cwd, 0, sizeof cwd);
	if(getcwd(cwd, sizeof(cwd)) != NULL){
		attron(COLOR_PAIR(1));
		addstr("NMINISHELL:");
		addstr(cwd);
		addstr("$:");
	}
	attroff(COLOR_PAIR(1));
}


int main(void){
	FILE *the_file;
	the_file =fopen(".nsmhist", "w");
	fclose(the_file);
	WINDOW *w;
	char c;
	int y,x;
	int cursorOffset=0;
	// int HISTORY_SIZE_LIMIT = 10;
	// int HISTORY_INDEX = 0;
	// int HISTORY_SIZE = 0;
	w=initscr();
	noecho();
	raw(); //line buffering disabled
	start_color(); // must be called to use colors
	scrollok(w,true);
	init_pair(1,COLOR_GREEN,COLOR_BLUE);
	init_pair(2,COLOR_BLACK,COLOR_WHITE);
	init_pair(3,COLOR_WHITE,COLOR_BLACK);
	init_pair(4,COLOR_RED,COLOR_GREEN);
	
	// Node the_head;
	// the_head = new_node("$",NULL,NULL);

	//struct s_node** the_command_history = (struct s_node**) malloc(sizeof(struct s_node) * HISTORY_SIZE_LIMIT);

	attron(COLOR_PAIR(2));
	addstr("Welcome to my terminal!\n");
	attroff(COLOR_PAIR(2));

	printMessage();

	char* the_clipboard;
	char the_command[250];
	int the_command_iterator=0;
	attron(COLOR_PAIR(3));
	for(;;){
		// fflush(stdout);
		c = getch();
		//printf("%s\n", "Sample text");
		switch(c){
			case 1: // CTRL A
				getyx(w,y,x);
				wmove(w,y,x - cursorOffset);
				cursorOffset = 0;
				break;
			case 5: //CTRL E
				getyx(w,y,x);
				wmove(w,y,x + (the_command_iterator - cursorOffset));
				cursorOffset = the_command_iterator;
				break;
			case 12:
			{
				//CTRL L, clear terminal except for current command
				//chtype* the_line;
				chtype* the_thing;
				the_thing = calloc((getmaxx(w)+1),sizeof(chtype));

				getyx(w,y,x);
				mvinchstr(y,0,the_thing);
				clear();

				addchstr(the_thing);
				wmove(w,0,x);

				break;
			}
			case 21: //CTRL U, remove line
				getyx(w,y,x);
				wmove(w,y,0);
				wclrtobot(w);
				the_clipboard = strdup(the_command);
				attroff(COLOR_PAIR(3));
				printMessage(); // we should do this last
				attron(COLOR_PAIR(3));
				wmove(w,y,x - cursorOffset);
				//wmove(w,y,x);

				memset(the_command, 0, sizeof the_command);
				the_command_iterator=0;
				cursorOffset=0;


				break;
			case 23:
			{ //CTRL W, remove word
				//simply get the current cursor position, translate that into the index of the
				//command, and then go backwards to the index of the first '\n'. Then go forwards
				//From index of '\n' to the index of the cursor. Grab that word, remove it from the command,
				//clear the line, redraw it the_command
				getyx(w,y,x);
				int space_index = 0;
				for(int find_space = cursorOffset;find_space>=0;find_space--){
					if(the_command[find_space]=='\n'){
						space_index = find_space;
					}else{
						break;
					}
				}

				char the_cut_command[the_command_iterator  - (cursorOffset + space_index) + 1]; // note 6, not 5, there's one there for the null terminator
				strncpy(the_cut_command, the_command, space_index);
				int hold_iterator = space_index+1;
				for(int place_the_rest = cursorOffset;place_the_rest<the_command_iterator;place_the_rest++){
					the_cut_command[hold_iterator] = the_command[place_the_rest];
					hold_iterator++;
				}

				char subbuff[cursorOffset - space_index];
				memcpy( subbuff, &the_command[space_index], cursorOffset - space_index );
				the_clipboard = strdup(subbuff);

				//the_clipboard = strdup(the_cut_command);
				wmove(w,y,0);
				wclrtobot(w);
				strcpy(the_command,the_cut_command);
				attroff(COLOR_PAIR(3));
				printMessage(); // we should do this last
				attron(COLOR_PAIR(3));
				wmove(w,y,x);
				//wmove(w,y,x);
				//
				
				break;
			}
			case 25: //CTRL Y, paste!
				addstr(the_clipboard);
				break;
			case 27: //means its an arrow key
				getch(); //flush the next '['
				switch(getch()){
					case 65: //Up arrow
						//addch('A');
						//addstr(elem_at(the_head,--HISTORY_INDEX));
						break;
					case 66: //Down arrow
						//addch('B');
						//addstr(elem_at(the_head,++HISTORY_INDEX));
						break;
					case 67: //Right
						getyx(w,y,x);
						if(cursorOffset<the_command_iterator && x!=getmaxx(w)-1){
							wmove(w,y,x+1);
							cursorOffset++;
						}else if(x==getmaxx(w)-1){
							wmove(w,y+1,0);
							cursorOffset++;
						}
						break;
					case 68: //Left
						getyx(w,y,x);
						if(cursorOffset!=0  && x!=0){
							wmove(w,y,x-1);
							cursorOffset--;
						}else if(x==0){
							wmove(w,y-1,getmaxx(w)-1);
							cursorOffset--;
						}
						break;
					default: // I have no clue lol
						addstr("\nThe arrowkey ascii values are wrong..\n");
						break;
				}
				break;
			case 127: //handle backspace/deleting characters
				if(the_command_iterator!=0 && cursorOffset!=0){
					//this works but it actually sucks lol
					
					//might need to do some logic here that figures out if at the end of the string
					//based off of the cursorOffset
					if(cursorOffset!=the_command_iterator){
						//this means we are not at the end
						char new_str[the_command_iterator];
						memset(new_str, 0, the_command_iterator);
						int new_str_it=0;
						int where_to_delete = cursorOffset==0 ? 0 : cursorOffset-1;
						for(int command_counter=0;command_counter<the_command_iterator;command_counter++){
							if(command_counter!=where_to_delete){
								new_str[new_str_it] = the_command[command_counter];
								new_str_it++;
							}
						}
						
						strcpy(the_command,new_str);

						getyx(w,y,x);
						wmove(w,y,0);
						wclrtobot(w);

						attroff(COLOR_PAIR(3));
						printMessage(); // we should do this last
						attron(COLOR_PAIR(3));
						wmove(w,y,x - cursorOffset);
						addstr(the_command);
						wmove(w,y,x-1);

					}else{
						//this means we are at the end of command string
						char new_str[the_command_iterator-1];
						memset(new_str, 0, the_command_iterator);
						strncpy(new_str,the_command,the_command_iterator-1);
						strncpy(the_command,new_str,the_command_iterator);
						getyx(w,y,x);
					
						if(x==0){
							mvdelch(y-1,getmaxx(w)-1);
						}else{
							mvdelch(y,x-1);
						}
					}
					the_command_iterator-=1;
					cursorOffset-=1;
					
				}
				break;
			case '\n':
			{
				const char s[2] = " ";
				char *token;
				char** the_array = (char**) calloc(1,sizeof(char*));
				int the_array_size = 1;
				int the_array_iterator = 0;
				/* get the first token */
				char* the_command_copy = strdup(the_command);
				token = strtok(the_command_copy, s);
				while( token != NULL ) {
					the_array = realloc(the_array,the_array_size * sizeof(char*));
					the_array[the_array_iterator] = token;
					// addstr("< ");
					// addstr(the_array[x-1]);
					// addstr(" > ,");
					the_array_iterator++;
					the_array_size++;
					token = strtok(NULL, s);
				}

				//now that we have the split up commands, check to see which command
				//it is and do the respective work
				if(the_array[0]){
					if(strcmp(the_array[0],"cd")==0){
						if(the_array[1]!=NULL && the_array_size==3){
							//the_array_size==3 because I do tas++ at end of loop,
							//only want the size of the command to be 2
							
							//do cd stuff here..
							if(chdir(the_array[1])==0){
								//succesfull changing direcories
								
							}else{
								//not successfull, print error message
								addstr("\n");
								addstr("ERROR: not a directory");
							}
						}else{
							addstr("\n");
							addstr("Usage:: cd <directory>");
						}
					}else if(strcmp(the_array[0],"help")==0){
						attroff(COLOR_PAIR(3));
						attron(COLOR_PAIR(4));
						addstr("\n");
						addstr("Welcome to my terminal! There is tons of stuff that you can do here.\n");
						addstr("On top of the basics of terminal, here are some of the commands.. \n");
						addstr("cd .. (Usage) cd <directory> .. changes directory\n");
						addstr("help .. But you already knew that\n");
						addstr("exit .. exits the terminal\n\n");
						addstr("Special flags\n");
						addstr("CTRL + A .. moves the cursor to the beg of the line\n");
						addstr("CTRL + E .. moves the cursor to the end of the line\n");
						addstr("CTRL + L .. clears the terminal except for current line\n");
						addstr("CTRL + U .. cuts the whole line");
						addstr("CTRL + W .. cuts the word");
						addstr("CTRL + Y .. pastes the clipboard!");
						attroff(COLOR_PAIR(4));
						attron(COLOR_PAIR(3));

					}else if(strcmp(the_array[0],"exit")==0){
						endwin();
						exit(0);
					}else if(the_array[0][0] == '$'){
						char out_command[250];
						int temp_iterator = 0;
						for(int temp=0;temp<the_command_iterator;temp++){
							if(the_command[temp]!= '(' && the_command[temp]!= '$' && the_command[temp]!= ')' && the_command[temp]!= '\0'){
								out_command[temp_iterator] = the_command[temp];
								temp_iterator++;
							}
						}
						out_command[temp_iterator] = '\0';
						// memcpy(out_command, &the_command[2], index_of_endpara);
						// out_command[index_of_endpara-2] = '\0';

						const char s[2] = " ";
						char *out_token;
						char** the_out_array = (char**) calloc(1,sizeof(char*));
						int the_out_size = 1;
						int the_out_iterator = 0;
						/* get the first token */
						char* the_out_copy = strdup(out_command);
						out_token = strtok(the_out_copy, s);
						while( out_token != NULL ) {
							the_out_array = realloc(the_out_array,the_out_size * sizeof(char*));
							the_out_array[the_out_iterator] = out_token;
							// addstr("< ");
							// addstr(the_array[x-1]);
							// addstr(" > ,");
							the_out_iterator++;
							the_out_size++;
							out_token = strtok(NULL, s);

						}

						execvp(the_out_array[0], the_out_array);
					}else{
						addstr("\n");
						//This means we do not know what the command is,
						//so send it to the actual terminal for exec
						//
						//unsigned int pid;

						// if(fork() == 0){
						// 	//my_str("execpv: \n");
						// 	//my_str(exe[1]);//execpv
						// 	//my_int(execvp(exe[0], exe));
							
						// 	if(execvp(the_array[0], the_array)<0){
						// 		//my_str("invalid command\n");
						// 	}
						// 	exit(0);
						
						// }else{
						// 	wait(NULL);
							
						// 	//my_str("Finished Executing\n");
						// }
						//trying something new
						
						int PATH_MAX = 200;
						FILE *fp;
						int status;
						char path[PATH_MAX];


						fp = popen(the_command, "r");
						if (fp == NULL)
						    /* Handle error */;


						while (fgets(path, PATH_MAX, fp) != NULL){
						    //printf("%s", path);
						    addstr(path);
						}


						status = pclose(fp);
						if (status == -1) {
						    /* Error reported by pclose() */
						    addstr("Error!\n");
						} else {
						    /* Use macros described under wait() to inspect `status' in order
						       to determine success/failure of command executed by popen() */
						    wait(NULL);
						}

					}
				}
				// my_char('H');
				// my_int('1');
				// //store the command in the linked list so we dont lose it
				// struct s_node* Node = new_node(the_command,NULL,node_at(*the_command_history,HISTORY_INDEX));
				// HISTORY_INDEX++;
				// if(HISTORY_SIZE_LIMIT - 5 <= HISTORY_INDEX){
				// 	HISTORY_SIZE_LIMIT*=2;
				// 	the_command_history = realloc(the_command_history,sizeof(struct s_node) * HISTORY_SIZE_LIMIT);
				// }
				// append(Node,the_command_history);
				// 
				// Add to linkedlist
				
				// if(HISTORY_SIZE==0){
				// 	remove_node(&the_head);
				// 	the_head = new_node(the_command,NULL,NULL);
				// }else{
				// 	add_elem(the_command,&the_head);
				// 	//addstr(elem_at(the_head,HISTORY_INDEX));
				// }
				// HISTORY_SIZE++;
				// HISTORY_INDEX++;

				//Save history to file
				//
				the_file =fopen(".nsmhist", "a+");
				fprintf(the_file,"%s\n",the_command);
				fclose(the_file);

				memset(the_command, 0, sizeof the_command);
				the_command_iterator=0;
				cursorOffset=0;
				addstr("\n");
				attroff(COLOR_PAIR(3));
				printMessage(); // we should do this last
				attron(COLOR_PAIR(3));
				break;
			}
			default:
				if(c >= 0 && c<= 31){
					//this means its signal
					switch(c){
						case 3:
							addstr("\nCannot exit. To exit please use the command exit");
							break;
						default:
							addstr("\n Not a recognized signal");
							break;
					}
				}else{
					//not a signal
					the_command[the_command_iterator] = c;
					the_command_iterator++;
					cursorOffset++;
					addch(c);
				}
				break;
		}
	}
	endwin();
	exit(0);
}
