#include "../../include/my.h"

int my_strindex(char* str, char c){
	if(str && c){
		for(int x=0;x<my_strlen(str);x++){
			if(str[x] == c){
				return x;
			}
		}
	}

	return -1;
}

