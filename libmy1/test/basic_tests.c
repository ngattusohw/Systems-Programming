#include "../include/my.h"

int main(){
	//my_alpha();
	my_num_base(9, "RTFM");
	my_digits();
	write(1,"\n",1);

	char c[] = "12345";
	my_int(my_strlen(c));


	return(0);
}