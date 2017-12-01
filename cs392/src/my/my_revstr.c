#include "my.h"

int my_revstr(char* str){
	int len = my_strlen(str);
    if(len < 2) {
        return len;
    }

    char *end = str + len - 1;
    while(str < end) {
        char temp = *str;
        *str++ = *end;
        *end-- = temp;
    }
    return len;
}

