#include "../../include/my.h"
#include <stdio.h>
/*
Takes a vector (array of string ended by a NULL)
Allocates a new string and copies each string from the array into new string separated by a single space, until NULL pointer to string is found
Returns new string
{"hello","world",NULL} -> "hello world"; 
 */
char *my_vect2str(char **x){
	if(x && *x){
		char* total = " ";
		for (char* c = *x; c!=NULL; c=*++x) {
		    total = my_strconcat(total,c);
		    total = my_strconcat(total, " ");
		    
		}

		printf("Hi\n");
		return total;
	}else{
		return NULL;
	}
}