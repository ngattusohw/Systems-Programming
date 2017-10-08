#include "../../include/my.h"

/*
Takes a vector (array of string ended by a NULL)
Allocates a new string and copies each string from the array into new string separated by a single space, until NULL pointer to string is found
Returns new string
{"hello","world",NULL} -> "hello world"; 
 */
char *my_vect2str(char **x){
	if(x){
		char* the_first = *x;
		while(the_first!=NULL){
			
		}
	}else{
		return "Not a valid string!";
	}
}