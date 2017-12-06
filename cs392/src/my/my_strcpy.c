#include "my.h"

/*
Copies the characters from src into dst overwriting what's already in there.
 Always copies a '\0'
 Assumes dst has enough memory allocated for the new string if it is longer.
 Does not allocate memory

 */


char* my_strcpy(char *dst, char *src){
	if(!dst || !src) return dst;

    char *str = dst;
    while(*src) {
        *(dst++) = *(src++);
    }

    *dst = '\0';
    return str;
}

