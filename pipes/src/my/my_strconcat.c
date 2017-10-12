#include "../../include/my.h"
#include <stdio.h>
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
		char* new_string = (char*) malloc(sizeof(char) * (a_length + b_length));
		
		for(int x=0;x<a_length;x++){
			new_string[x] = a[x];
		}

		int z=0;
		for(int y=a_length;y<(a_length + b_length);y++){
			new_string[y] = b[z];
			z++;
		}
		return new_string;

	}else{
		return NULL;
	}
}

