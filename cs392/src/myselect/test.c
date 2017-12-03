#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <ncurses.h>

int main(void) {
	int width, height;
	setupterm(NULL, fileno(stdout), (int *)0);
	width = tigetnum("cols");
	height = tigetnum("lines");
	printf("The terminal is %d columns wide and %d lines high\n", width, height);
	exit(0);
}