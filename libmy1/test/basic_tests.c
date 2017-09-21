#include "../include/my.h"
#include <string.h>
#include <stdio.h>

int main(){
	//my_alpha();
	// my_num_base(9, "RTFM");
	// my_digits();
	// write(1,"\n",1);

	// char c[] = "12345";
	// my_int(my_strlen(c));
	// write(1,"\n",1);

	// char it = 'a';
	// my_int(my_strindex(c,it));

	// write(1,"\n",1);

	// my_int(my_strrindex("aabbac",'d'));

	// write(1,"\n",1);

	// char hi[6];
	// strcpy(hi,"");
	// my_int(my_revstr(hi));

	// write(1,"\n",1);
	// 
	// my_str("This is my string\n");
	// my_int(10);

	// write(1,"\n",1);

	// my_num_base(10,"");

	// write(1,"\n",1);
	// my_alpha();

	// write(1,"\n",1);

	// my_digits();

	// write(1,"\n",1);

	// my_int(my_strindex("" , 'H'));

	// write(1,"\n",1);

	// my_int(my_strrindex("This is my string", 'i'));

	// write(1,"\n",1);

	// my_int(my_strlen(""));

	// write(1,"\n",1);

	// char hi[6];
	// strcpy(hi,"Hello");

	// my_int(my_revstr(hi));

	// write(1,"\n",1);

	my_str(my_strfind("String", 's'));

	write(1,"\n",1);

	my_str(my_strrfind("Strings", 's'));

	write(1,"\n",1);

	printf("%d \n", my_strcmp("First", "Second"));

	write(1,"\n",1);

	char dest[10];

	printf("%s\n", my_strcpy(dest, "Hi"));

	char hi[10];
	printf("%s\n", my_strcat(hi, NULL));

	printf("%s\n", my_strdup(NULL));

	printf("%s\n", my_strconcat("NULadL", NULL));

	printf("%d\n", my_atoi(NULL));





	return(0);
}