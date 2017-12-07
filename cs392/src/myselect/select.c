#include <stddef.h>
#include <stdlib.h>
#include "my.h"
#include <stdlib.h>
#include <ncurses.h>

int mrow, mcol, crow, ccol, lrow, lcol;
int *selected;

void toggle_underline(char **argv, int max_length){
	if (selected[crow + (ccol / max_length) * mrow] == 1){
		attron(A_UNDERLINE | A_STANDOUT);
	}else{
		attron(A_UNDERLINE);
	}
	addstr(argv[1 + crow + (ccol / max_length) * mrow]);
	attroff(A_UNDERLINE);
	if (selected[crow + (ccol / max_length) * mrow] == 1){
		attroff(A_STANDOUT);
	}
}

void move_down(char **argv, int max_length){
	/* remove underline/ highlight */
	if (selected[crow + (ccol / max_length) * mrow] == 1){
		attron(A_STANDOUT);
	}
	addstr(argv[1 + crow + (ccol / max_length) * mrow]);
	if (selected[crow + (ccol / max_length) * mrow] == 1){
		attroff(A_STANDOUT);
	}

	/* move */
	if (crow == lrow && ccol == lcol){
		crow = 0;
		ccol = 0;
	}else if (crow == mrow - 1){
		crow = 0;
		ccol += max_length;
	}else{
		crow++;
	}
	move(crow, ccol);

	/* underline/highlight */
	toggle_underline(argv, max_length);

	move(crow, ccol);
}



int initialize_window(char** argv, int max_length){
	int small_flag;
	int i;
	clear();
	getmaxyx(stdscr, mrow, mcol);
	crow = 0;
	ccol = 0;
	small_flag = 0;
	/* print files in columns */
	for (i = 1; argv[i] != NULL; i++){
		/* if row overflow */
		if (crow == mrow){
			/* reset row and increment column */
			crow = 0;
			ccol += max_length;
			/* if cant fint new row */
			
		}

		if (ccol + my_strlen(argv[i]) >= mcol){
				/* print resize window */
				ccol = 0;
				clear();
				addstr("Please enlarge the window!");
				refresh();
				small_flag = 1;
				break;
		}
		/* print string */
		if (selected[crow + (ccol / max_length) * mrow] == 1)
			attron(A_STANDOUT);
		mvaddnstr(crow, ccol, argv[i], max_length - 1);
		if (selected[crow + (ccol / max_length) * mrow] == 1)
			attroff(A_STANDOUT);
		refresh();
		crow++;
	}
	/* store last r/c */
	lrow = crow - 1;
	lcol = ccol;
	/* move to top left */
	move(0, 0);
	crow = 0;
	ccol = 0;
	return small_flag;
}

int main(int argc, char **argv){
	int i;
	int max_length = 0;
	int ch, small_flag;
	
	if (argc < 2){
		my_str("Usage: ./my_select [stuff you want to select from]\n");
		exit(0);
	}
	
	newterm(NULL, stderr,stdin);
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	selected = (int *) malloc(sizeof(int) * (argc - 1));
	mrow = mcol = crow = ccol = lrow = lcol = 0;
	small_flag = 0;
	ch = 0;
	//get the lognest string within the arguments to set up column width
	for (i = 1; argv[i] != NULL; i++){
		if (my_strlen(argv[i]) >= max_length){
			max_length = my_strlen(argv[i]);
		}
	}
	max_length++;
	/*initialize selected */
	for (i = 0; i < argc - 1; i++){
		selected[i] = 0;
	}
	/* init screen */
    small_flag = initialize_window(argv, max_length);
	//make first underline
	if (small_flag == 0){
		attron(A_UNDERLINE);
		addstr(argv[1]);
		attroff(A_UNDERLINE);
	}
	move(0, 0);
	
	while (1){
		ch = getch();
		/* escape quits */
		if (ch == KEY_RESIZE){
			/* reinit screen */
			small_flag = initialize_window(argv, max_length);
			/* if displaying files, make first underlined and highlighted if needed*/
			if (small_flag == 0){
				if (selected[crow + (ccol / max_length) * mrow] == 1)
					attron(A_UNDERLINE | A_STANDOUT);
				else
					attron(A_UNDERLINE);
				addstr(argv[1]);
				attroff(A_UNDERLINE);
				if (selected[crow + (ccol / max_length) * mrow] == 1)
					attroff(A_STANDOUT);
			}
			move(0, 0);
		}else if (ch == 27){
			endwin();
			exit(0);
		}else if (ch == KEY_ENTER || ch == '\n'){
			break;
		}else if (ch == ' '){
			if (selected[crow + (ccol / max_length) * mrow] == 1){
				selected[crow + (ccol / max_length) * mrow] = 0;
				/* remove highlight and replace with underline */
				attron(A_UNDERLINE);
				addstr(argv[1 + crow + (ccol / max_length) * mrow]);
				attroff(A_UNDERLINE);
				move(crow, ccol);
			}else{
				selected[crow + (ccol / max_length) * mrow] = 1;
				move_down(argv, max_length);
			}
		}else if (ch == KEY_LEFT){
			if (selected[crow + (ccol / max_length) * mrow] == 1){
				attron(A_STANDOUT);
			}
			addstr(argv[1 + crow + (ccol / max_length) * mrow]);
			if (selected[crow + (ccol / max_length) * mrow] == 1){
				attroff(A_STANDOUT);
			}
			/* move cursor */
			if (ccol == 0){
				crow = 0;
			}else{
				ccol -= max_length;
			}
			move(crow, ccol);
			//now add the underline
			toggle_underline(argv, max_length);
			/* reset cursor */
			move(crow, ccol);
		}else if (ch == KEY_RIGHT){
			/* remove underline */
			if (selected[crow + (ccol / max_length) * mrow] == 1)
				attron(A_STANDOUT);
			addstr(argv[1 + crow + (ccol / max_length) * mrow]);
			if (selected[crow + (ccol / max_length) * mrow] == 1)
				attroff(A_STANDOUT);
			/* move cursor */
			if ((ccol + max_length) > lcol)
				crow = lrow;
			else
				ccol += max_length;

			if (ccol == lcol && crow > lrow)
				crow = lrow;

			move(crow, ccol);
			/* underline */
			toggle_underline(argv, max_length);
			/* reset cursor */
			move(crow, ccol);
		}else if (ch == KEY_DOWN){
			move_down(argv, max_length);

		}else if (ch == KEY_UP){
			if (selected[crow + (ccol / max_length) * mrow] == 1){
				attron(A_STANDOUT);
			}
			addstr(argv[1 + crow + (ccol / max_length) * mrow]);
			if (selected[crow + (ccol / max_length) * mrow] == 1){
				attroff(A_STANDOUT);
			}

			/* move */
			if (crow == 0){
				if (ccol == 0){
					crow = lrow;
					ccol = lcol;
				}else{
					ccol -= max_length;
					crow = mrow - 1;
				}
				
			}else{
				crow--;
			}
			move(crow, ccol);
			/* underline / highlight */
			if (selected[crow + (ccol / max_length) * mrow] == 1){
				attron(A_UNDERLINE | A_STANDOUT);
			}else{
				attron(A_UNDERLINE);
			}

			addstr(argv[1 + crow + (ccol / max_length) * mrow]);
			attroff(A_UNDERLINE);
			if (selected[crow + (ccol / max_length) * mrow] == 1){
				attroff(A_STANDOUT);
			}
			move(crow, ccol);
		}
		refresh();
	}
				
	endwin();
	//now output the stuff
	for (i = 0; i < argc - 1; i++){
		if (selected[i] != 0){
			my_str(argv[i + 1]);
			my_char(' ');
		}
	}
	my_char('\n');
	
	return 0;
}
