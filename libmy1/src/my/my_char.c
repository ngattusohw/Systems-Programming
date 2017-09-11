#include "../../include/my.h"

void my_char(char c){
	/*Write the contents of c to standard out, which is file descriptor 1*/
	write(1, &c, 1);
}


int main() {
	char a = '1';
	my_char(a);

	return(0);
}