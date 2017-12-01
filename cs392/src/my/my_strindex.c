#include "my.h"

int my_strindex(char* str, char c){
	if(str && c){
		for(int x=0; str && *str;str++){
			if(*str == c){
				return x;
			}
			x++;
		}
	}

	return -1;
}

