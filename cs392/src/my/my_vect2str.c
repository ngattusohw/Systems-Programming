#include "my.h"
#include <stdio.h>

/*
Takes a vector (array of string ended by a NULL)
Allocates a new string and copies each string from the array into new string separated by a single space, until NULL pointer to string is found
Returns new string
{"hello","world",NULL} -> "hello world"; 
 */
char *my_vect2str(char **x){
	if(!x){
		return NULL;
	}else{
	    int i = 0, size = 0;
	    while(x[i]) {
	        size += my_strlen(x[i]);
	        ++i;
	    }

	    i = 0;
	    char *str = malloc(size);
	    while(x[i+1]) {
	        my_strcat(str, x[i]);
	        my_strcat(str, " ");
	        ++i;
	    }
	    my_strcat(str, x[i]);
	    printf("THIS IS THE STRING %s\n", str);
	    return str;
	}
}

