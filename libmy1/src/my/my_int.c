#include "../../include/my.h"

void my_int(int i){
	//char c = (char) i;
	//write(1, &c, sizeof c);
	write(1, &i, sizeof(i));
}


// int main(){
// 	int a = 66;
// 	my_int(a);

// 	return(0);
// }