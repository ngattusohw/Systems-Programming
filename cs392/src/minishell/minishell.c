#include "my.h"
#include <signal.h>
#include <string.h>

#define SIZE 100

int main(){
	pid_t pid;

	signal(SIGINT, SIG_IGN);

	while(1){
		char cwd[1024];
		if(getcwd(cwd, sizeof(cwd)) != NULL){

			my_str("MINISHELL: ");
			my_str(cwd);
			my_str("$: ");
			char buffc[SIZE];

			memset(buffc, 0, SIZE*sizeof(char));

			read(0, buffc, SIZE);
			//my_str(buffc);
			char** what_to_do = my_str2vect(buffc);
			//printf("%s\n", );
			if(!what_to_do){
				continue;
			}
			else if(my_strcmp(what_to_do[0],"cd") == 0){
				if(what_to_do[1]){
					if(chdir(what_to_do[1])==-1){
						my_str("Not a valid directory\n");
					}
				}else{
					my_str("Usage:: cd <directory>\n");
				}
			}else if(my_strcmp(what_to_do[0],"exit") == 0){
				//my_str("In exit");
				exit(0);
			}else if(my_strcmp(what_to_do[0],"help") == 0){
				my_str("It seems that you need help!\n");
				my_str("The minishell commands are:: cd, exit, and help!\n");
				my_str("Usage:: cd <directory> , exit, and help\n");
			}else{
				//my_str("I should do stuff\n");
				if(what_to_do && what_to_do[0]!=NULL){
					pid = fork();
					if(pid==0){
						if(execvp(what_to_do[0],what_to_do) == -1){
							my_str("Not a valid command!\n");
						}
						exit(0);
					}else if(pid<0){
						my_str("Fork failed!");
					}else{
						wait(NULL);
					}
				}else{
					my_str("Error!\n");
				}
			}
			
			int clear_array = 0;
			while(what_to_do[clear_array]!=NULL){
				//free(what_to_do[clear_array]);
				// my_str(what_to_do[clear_array]);
				// my_str("\n");
				what_to_do[clear_array] = NULL;
				clear_array++;
			}
			free(what_to_do);
			what_to_do = NULL;
		}else{
		   // perror("getcwd() error");
		   // exit(1);
		}


	}


	return 0;
}
