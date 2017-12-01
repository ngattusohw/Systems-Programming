#include "my.h"

/*
Copies the characters from src into dst overwriting what's already in there.
 Always copies a '\0'
 Assumes dst has enough memory allocated for the new string if it is longer.
 Does not allocate memory

 */


char* my_strcpy(char *dst, char *src){
	if(dst && src){
		if(my_strlen(dst) >= my_strlen(src)){
			//problem is where to end string, might add /0? idk
			for(int x=0;x<my_strlen(src);x++){
				dst[x] = src[x];
			}
		}else{
			for(int x=0;x<my_strlen(dst);x++){
				dst[x] = src[x];
			}
			//theres not enough space, what do i do?
		}
		return dst;
	}else{
		return NULL;
	}
}

