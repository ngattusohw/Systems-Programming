#include "../../include/my.h"

int my_revstr(char* str){
	int x = 0;
	if(str && my_strlen(str)>0){
		int y = my_strlen(str) -1;
		while(x!=y){
			char hold = str[x];
			str[x] = str[y];
			str[y] = hold;
			y--;
			x++;
		}
		return my_strlen(str);
	}else{
		return -1;
	}
}

