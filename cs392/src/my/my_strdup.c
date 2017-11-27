#include "../../include/my.h"

/*
Allocates new memory 
Copies str into that new memory 
returns pointer to new string
 */

char* my_strdup(char *src){
	if(src){
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
		
		char *str;
	    char *p;
	    int len = 0;

	    while (src[len])
	        len++;
	    str = malloc(len + 1);
	    p = str;
	    while (*src)
	        *p++ = *src++;
	    *p = '\0';
	    return str;

	}else{
		return NULL;
	}
}

