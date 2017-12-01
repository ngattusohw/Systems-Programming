#include "my.h"

/*
Same as my_strconcat except:
Copies all of a and then n chars or length of b
 */


char *my_strnconcat(char *a, char *b, int n){
	if(!a && !b) {
		return NULL;
	}else if(!b) {
		return my_strdup(a);
	}else if(n < 0) {
		n = 0;
	}

	char *new_string;
	int len_b = my_strlen(b);
	int min = len_b < n ? len_b : n;

	if(!a) {
		new_string = malloc(min + 1);
		my_strncpy(new_string, b, min);
	}else{
		int len_a = my_strlen(a);
		new_string = malloc(len_a + min + 1);
		my_strcpy(new_string, a);
		my_strncpy(new_string + len_a, b, min);
	}
	return new_string;
}

