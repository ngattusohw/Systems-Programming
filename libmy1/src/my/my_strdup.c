#include "../../include/my.h"

/*
Allocates new memory 
Copies str into that new memory 
returns pointer to new string
 */

char* my_strdup(char *str){
	if(str){
		char* new_string = (char*) malloc(sizeof(char) * my_strlen(str));
		my_strcpy(new_string,str);
		return new_string;
		//I think above might cause a problem
	}else{
		return NULL;
	}
}

