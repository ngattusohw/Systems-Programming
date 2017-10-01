#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


/*
This was an extra credit lab that was not finished

 */

int fib(int n){
	pid_t pid = fork();
	if (pid == -1) {
	  // error, no child created
	}
	else if (pid == 0) {
		//child
		if (n <= 1){
      		return n;
		}else{
			
			//return 
		}
	  
	}else{
		// parent
		int status;
		if (waitpid(pid, &status, 0) == -1) {
		// handle error
		}else{
			// child exit code in status
			// use WIFEXITED, WEXITSTATUS, etc. on status
			if (n <= 1){
				return n;
			}else{
				char *command = "./fibo";
				char *arguments[] = { "command", n, "second argument", NULL };
				execvp(command, arguments);
				// fork();
				// return 
			}
		}
	}	
}

int main(int argc, char *argv[] )  {
	if( argc == 2 ){

		printf("The argument supplied is %s\n", argv[1]);
	}
	return(0);
}