#include "../../include/my.h"

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
	 while(*a && (*a == *b)){
        a++;
        b++;
    }
    return *(const unsigned char*)a - *(const unsigned char*)b;	
}
