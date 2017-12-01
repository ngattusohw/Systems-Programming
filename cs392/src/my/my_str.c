#include "my.h"

void my_str(char* c){
	if(c==NULL){
		return;
	}else{
		write(1,c,my_strlen(c));
	}
}
