#include "../../include/my.h"

/*
Returns a pointer to the first char in the string which matches.
Return NULL if the letter is not found.

 */

char* my_strfind(char* str, char c){
	if(str && c){
		int index = my_strindex(str,c);
		if(index!=-1){
			char it = str[index];
			char* its_pointer = &it;
			return its_pointer;
		}
	}

	return NULL;
}

