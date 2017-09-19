#include "../../include/my.h"

/*
	Returns a pointer to the last char in the string which matches.
	Return NULL if the letter is not found.
 */

char* my_strrfind(char* str, char c){	
	if(str && c){
		int index = my_strrindex(str,c);
		if(index!=-1){
			char* it = str[index];
			return it;
		}
	}

	return NULL;
}