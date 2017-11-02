#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <ncurses.h>
/*
Compile this with -lncurses
 */
int main(void){
	char *bold, *offbold;
	setupterm(NULL, fileno(stdout), (int *)0);
	bold = tigetstr("smso");
	offbold = tigetstr("rmso");
	putp(bold);
	printf("This should be highlighted\n");
	putp(offbold);
	beep();
	exit(0);
}