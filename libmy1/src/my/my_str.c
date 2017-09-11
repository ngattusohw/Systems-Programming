#include "../../include/my.h"


//returns the size of a character array using a pointer to the first element of the character array
int size(char *ptr){
    int offset = 0;
    int count = 0;
    while(*(ptr + offset) != '\0'){
        count++;
        offset++;
    }
    return count;
}

void my_str(char* c){
	if(c==NULL){
		return;
	}else{
		// while (*(c++) != '\0'){
		// 	write(1,"H",2);
		// }
		write(1,c,size(c));
	}
}


int main(){
	char a[] = "Hello World!\n\0";
	my_str(a);

	return(0);
}