#include "../../include/my.h"
#include <stdio.h>

#define SIZE 100

int main(){

	while(1){
		char cwd[1024];
		if(getcwd(cwd, sizeof(cwd)) != NULL){

			my_str("MINISHELL: ");
			my_str(cwd);
			my_str("$: ");


			char buffc[SIZE];
			read(0, buffc, SIZE);
			//my_str(buffc);
			char** what_to_do = my_str2vect(buffc);

			if(my_strcmp(what_to_do[0],"cd") == 0){
				if(what_to_do[1]){
					if(chdir(what_to_do[1])==-1){
						my_str("Not a valid directory\n");
					}
				}else{
					my_str("Usage:: cd <directory>\n");
				}
			}else if(my_strcmp(what_to_do[0],"exit") == 0){
				my_str("In exit");
				exit(1);
			}else if(my_strcmp(what_to_do[0],"help") == 0){
				my_str("It seems that you need help!\n");
				my_str("The minishell commands are:: cd, exit, and help!\n");
				my_str("Usage:: cd <directory> , exit, and help\n");
			}else{
				my_str("I should do stuff\n");
				if(execvp(what_to_do[0],what_to_do) == -1){
					my_str("WE failed!\n");
				}
			}

		}else{
		   perror("getcwd() error");
		   exit(1);
		}

	}


	return 0;
}
