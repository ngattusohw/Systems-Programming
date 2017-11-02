
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(void) {
	struct termios initial_settings, new_settings;
	char key[6] = "x";
	int num_chars;
	tcgetattr(fileno(stdin), &initial_settings);
	new_settings = initial_settings;
	new_settings.c_lflag &= ~ICANON;
	new_settings.c_lflag &= ~ECHO;
	new_settings.c_cc[VMIN] = 1;
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_iflag &= ~ICRNL;
	if(tcsetattr(fileno(stdin), TCSAFLUSH, &new_settings) != 0) {
		fprintf(stderr,"Could not set attributes\n");
		exit(1);
	}
	while (key[0] != 'q') {
		printf("Hit any key: ");
		fflush(stdout);
		num_chars = read(fileno(stdin), key, 3);
		key[num_chars] = '\0';
		if (key[0] == '\015')
			strcpy(key, "Enter");
		else if (strcmp(key, "^[[A") == 0)
			strcpy(key, "Up");
		else if (strcmp(key, "^[[B") == 0)
			strcpy(key, "Down");
		else if (strcmp(key, "^[[D") == 0)
			strcpy(key, "Left");
		else if (strcmp(key, "^[[C") == 0)
			strcpy(key, "Right");
		printf("\nYou entered %s\n", key);
	}
	tcsetattr(fileno(stdin), TCSANOW, &initial_settings);
	exit(0);
}

