#include "my.h"

/*
Allocates new memory 
Copies str into that new memory 
returns pointer to new string
 */

char* my_strdup(char *str){
	if(str){
		//char* new_string = (char*) malloc(sizeof(char) * my_strlen(str));
		// char new_string[my_strlen(str)];
		// int iterator = 0;
		// while(str[iterator] && str[iterator]!= '\0'){
		// 	new_string[iterator] = str[iterator];
		// 	iterator++;
		// }
		// new_string[iterator] = '\0';
		// //my_strcpy(new_string,str);
		// return new_string;
		//I think above might cause a problem
		//
		//
		
		char *dst = (char *) malloc(my_strlen(str) + 1);
		return my_strcpy(dst, str);
	}else{
		return NULL;
	}
}

