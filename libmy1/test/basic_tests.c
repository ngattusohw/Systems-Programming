#include "../include/my.h"
#include <string.h>
#include <stdio.h>

int main(){
	//my_alpha();
	my_num_base(9, "RTFM");
	my_digits();
	write(1,"\n",1);

	char c[] = "12345";
	my_int(my_strlen(c));
	write(1,"\n",1);

	char it = 'a';
	my_int(my_strindex(c,it));

	write(1,"\n",1);

	my_int(my_strrindex("aabbac",'d'));

	write(1,"\n",1);

	char hi[6];
	strcpy(hi,"");
	my_int(my_revstr(hi));

	write(1,"\n",1);

	return(0);
}