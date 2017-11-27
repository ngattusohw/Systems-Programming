#include "../include/my.h"
#include <string.h>
#include <stdio.h>

int main(){
	
	// char** the_array = my_str2vect("   \t  Hello \t      World    \t     !   \t");

	// printf("TEST PRINT %s\n", the_array[0]);
	// for(int x=0;the_array[x]!=NULL;x++){
	// 	printf("<%s> , ", the_array[x]);
	// }
	// printf("\n");
	// 
	// char* the_string = "F";
	// my_num_base(9,the_string);
	
	//my_alpha();


	char** hello = my_str2vect("Hello \t      World    \t     !   \t");
	for(int x=0;x<sizeof(hello);x++){
		printf("<%s>,", hello[x]);
	}
	printf("\n");


	//return(0);
}