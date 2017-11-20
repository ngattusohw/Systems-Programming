// #include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>


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

	WINDOW *w;
	char c;
	int y,x;
	int cursorOffset=0;
	w=initscr();
	noecho();
	//raw(); //line buffering disabled
	start_color(); // must be called to use colors
	scrollok(w,true);
	init_pair(1,COLOR_GREEN,COLOR_BLUE);
	init_pair(2,COLOR_BLACK,COLOR_WHITE);
	init_pair(3,COLOR_WHITE,COLOR_BLACK);
	init_pair(4,COLOR_RED,COLOR_GREEN);

	attron(COLOR_PAIR(2));
	addstr("Welcome to my terminal!\n");
	attroff(COLOR_PAIR(2));

	printMessage();

	char the_command[250];
	int the_command_iterator=0;
	attron(COLOR_PAIR(3));
	for(;;){
		// fflush(stdout);
		c = getch();
		//printf("%s\n", "Sample text");
		switch(c){
			// case 2:
			// 	// setupterm(NULL, fileno(stdout), (int *)0);
			// 	// if(toggles[2]==0){
			// 	// 	//bold = tigetstr("smso");
			// 	// 	//putp(bold);
			// 	// 	attron(A_BOLD);
			// 	// 	toggles[2]=1;
			// 	// 	//printf("%s\n", "HI");
			// 	}else{
			// 		// // offbold = tigetstr("rmso");
			// 		// // putp(offbold);
			// 		// attroff(A_BOLD);
			// 		// toggles[2]=0;
			// 	}
			// 	break;
			// case 9:
			// 	if(toggles[9]==0){
			// 		//attron(A_ITALIC);
			// 		toggles[9]=1;
			// 	}else{
			// 		//attroff(A_ITALIC);
			// 		toggles[9]=0;
			// 	}
			// 	break;
			// case 21:
			// 	//setupterm(NULL, fileno(stdout), (int *)0);
			// 	if(toggles[21]==0){
			// 		//tcsetattr(fileno(stdin), A_UNDERLINE, &new_settings);
			// 		attron(A_UNDERLINE);
			// 		//printf("I am highlighted!\n");
			// 		toggles[21]=1;
			// 	}else{
			// 		attroff(A_UNDERLINE);
			// 		toggles[21]=0;
			// 	}
			// 	break;
			// case 12:
			// 	if(toggles[12]==0){
			// 		attron(A_BLINK);
			// 		toggles[12]=1;
			// 	}else{
			// 		attroff(A_BLINK);
			// 		toggles[12]=0;
			// 	}
			// 	break;
			// case 18:
			// 	attroff(A_BLINK);
			// 	attroff(A_UNDERLINE);
			// 	//attroff(A_ITALIC);
			// 	attroff(A_BOLD);
			// 	for(int x=0;x<26;x++){
			// 		toggles[x]=0;
			// 	}
			// 	break;
			// case 7:
			// 	if(toggles[7]==0){
			// 		attron(COLOR_PAIR(1));
			// 		toggles[7]=1;
			// 	}else{
			// 		attroff(COLOR_PAIR(1));
			// 		toggles[7]=0;
			// 	}
			// 	break;
			// case 11:
			// 	if(toggles[11]==0){
			// 		attron(COLOR_PAIR(2));
			// 		toggles[11]=1;
			// 	}else{
			// 		attroff(COLOR_PAIR(2));
			// 		toggles[11]=0;
			// 	}
			// 	break;
			// case 23:
			// 	if(toggles[23]==0){
			// 		attron(COLOR_PAIR(3));
			// 		toggles[23]=1;
			// 	}else{
			// 		attroff(COLOR_PAIR(3));
			// 		toggles[23]=0;
			// 	}
			// 	break;
			// case 17:
			// 	endwin();
			// 	exit(0);
			case 1: // CTRL A
				getyx(w,y,x);
				wmove(w,y,x - cursorOffset);
				cursorOffset = 0;
				break;
			case 5:
				getyx(w,y,x);
				wmove(w,y,x + (the_command_iterator - cursorOffset));
				cursorOffset = the_command_iterator;
				break;
			case 9:
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
			case 20: //CTRL T Test
				addstr(the_command);
				break;
			case 27: //means its an arrow key
				getch(); //flush the next '['
				switch(getch()){
					case 65: //Up arrow
						addch('A');
						break;
					case 66: //Down arrow
						addch('B');
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

					}else{
						//this means we are at the end of command string
						char new_str[the_command_iterator-1];
						memset(new_str, 0, the_command_iterator);
						strncpy(new_str,the_command,the_command_iterator-1);
						strncpy(the_command,new_str,the_command_iterator);
					}

					the_command_iterator-=1;
					cursorOffset-=1;
					getyx(w,y,x);
					
					if(x==0){
						mvdelch(y-1,getmaxx(w)-1);
					}else{
						mvdelch(y,x-1);
					}
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
				token = strtok(the_command, s);
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
						attroff(COLOR_PAIR(4));
						attron(COLOR_PAIR(3));

					}else if(strcmp(the_array[0],"exit")==0){
						endwin();
						exit(0);
					}
				}



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
				the_command[the_command_iterator] = c;
				the_command_iterator++;
				cursorOffset++;
				addch(c);
		}
	}


	// char *bold, *offbold;
	// setupterm(NULL, fileno(stdout), (int *)0);
	// bold = tigetstr("smso");
	// offbold = tigetstr("rmso");
	// putp(bold);
	// printf("This should be highlighted\n");
	// putp(offbold);
	// beep();
	endwin();
	exit(0);
}
