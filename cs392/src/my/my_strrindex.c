#include "../../include/my.h"

int my_strrindex(char* str, char c){
	int index = -1;
	if(str && c){
		for(int x=0;x<my_strlen(str);x++){
			if(str[x] == c){
				index = x;
			}
		}
	}

	return index;
}

