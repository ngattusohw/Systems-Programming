#include "../../include/my.h"
#include <stdio.h>

#define SIZE 100

int main(){

	printf("MINISHELL : %s $", "FUCK");


	while(1){
		char cwd[1024];
		if(getcwd(cwd, sizeof(cwd)) != NULL){

			printf("MINISHELL : %s $", cwd);


			// char buffc[SIZE];
			// read(0, buffc, SIZE);
			// my_str(buffc);



		}else{
		   perror("getcwd() error");
		   exit(1);
		}

		

	}


	return 0;
}
