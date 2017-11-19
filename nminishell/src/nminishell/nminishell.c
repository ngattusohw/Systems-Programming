// #include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <ncurses.h>

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
	w=initscr();
	noecho();
	start_color(); // must be called to use colors
	init_pair(1,COLOR_GREEN,COLOR_BLUE);
	init_pair(2,COLOR_BLACK,COLOR_WHITE);
	init_pair(3,COLOR_WHITE,COLOR_BLACK);

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
			case '\n':
				memset(the_command, 0, sizeof the_command);
				the_command_iterator=0;
				addstr("\n");
				attroff(COLOR_PAIR(3));
				printMessage(); // we should do this last
				attron(COLOR_PAIR(3));
				break;

			default:
				the_command[the_command_iterator] = c;
				the_command_iterator++;
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