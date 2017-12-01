#include "my.h"

/*
Compares strings by ascii value
 If a and b are identical, return 0. 
 if a < b, return negative number 
 if a > b, return positive number
 Two NULL are equal.
 NULL is always less than a normal string
*/

/*
THIS IS WRONG
 */
int my_strcmp(char* a, char* b){
	if(!a){
		return !b ? 0 : -1;
	}else if(!b){
    	return 1;
    }

	 while(*a && (*a == *b)){
        a++;
        b++;
    }
    return *a - *b;	
}
