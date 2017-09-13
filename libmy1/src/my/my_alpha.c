#include "../../include/my.h"

void my_alpha(){
	for(int x = 65; x<91;x++){
		write(1, &x, sizeof(x));
	}
	
}


// int main(){
// 	int a = 66;
// 	my_int(a);

// 	return(0);
// }