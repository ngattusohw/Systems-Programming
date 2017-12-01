#include "my.h"
/*
 Allocates new memory 
 Copies concatenated strings in that new memory 
 Returns pointer to it
 If both NULL return NULL
 */

char* my_strconcat(char *a, char *b){
	if(a && b){
		int a_length = my_strlen(a);
		int b_length = my_strlen(b);
		int size = a_length + b_length;
		char* new_string = (char*) malloc(sizeof(char) * (size));
		
		my_strcpy(new_string, a);
		my_strcat(new_string, b);
		return new_string;

	}else if(!b){
		return my_strdup(a);
	}else if(!a){
		return my_strdup(b);
	}else{
		return NULL;
	}
}


