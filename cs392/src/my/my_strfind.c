#include "my.h"

/*
Returns a pointer to the first char in the string which matches.
Return NULL if the letter is not found.

 */

char* my_strfind(char* str, char c){
	if(str && c){
		int index = my_strindex(str,c);
		if(index>=0){
			return &str[index];
		}else{
			return NULL;
		}
	}

	return NULL;
}

