#include "../../include/my.h"

/*
Takes a vector (array of string ended by a NULL)
Allocates a new string and copies each string from the array into new string separated by a single space, until NULL pointer to string is found
Returns new string
{"hello","world",NULL} -> "hello world"; 
 */
char *my_vect2str(char **x){
	if(x && *x){
		char* hold = *x;
		char* total = my_strdup(hold);
		while(hold!=NULL){
			hold=*++x;
			
		}
	}else{
		return "Not a valid string!";
	}
}