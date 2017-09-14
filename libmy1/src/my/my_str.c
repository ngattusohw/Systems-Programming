#include "../../include/my.h"

void my_str(char* c){
	if(c==NULL){
		return;
	}else{
		// while (*(c++) != '\0'){
		// 	write(1,"H",2);
		// }
		write(1,c,my_strlen(c));
	}
}


// int main(){
// 	char a[] = "Hello World!\n\0";
// 	my_str(a);

// 	return(0);
// }