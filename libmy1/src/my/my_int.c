#include "../../include/my.h"

void my_int(int i){
	/*Write the contents of c to standard out, which is file descriptor 1*/
	write(1, &i, 1);
}


int main(){
	int a = 1;
	my_int(a);

	return(0);
}