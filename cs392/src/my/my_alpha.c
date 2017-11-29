#include "../../include/my.h"

void my_alpha(){
	for(int x = 65; x<91;x++){
		write(1, &x, sizeof(char));
	}
	write(1,"\n\0", 1);
	//write(1,"\0", 1);
	
}
