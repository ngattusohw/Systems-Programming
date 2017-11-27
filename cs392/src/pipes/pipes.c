#include "my.h"
#include <sys/wait.h>

#define SIZE 100

int main(int argc, char* argv[]){
	if(argc <= 1){
        my_str("Not enough arguments!\n");
        return 1; 
    }

    int fd[2];
    char buff[SIZE];
    char* the_str = my_vect2str(&argv[1]);

    pipe(fd);

    if(fork()==0){
        //in the child
        int fdc[2];
        char buffc[SIZE];
        pipe(fdc);

        if(fork()){
            close(fdc[1]);
            read(fdc[0], buffc, SIZE);

            my_str("Grandchild: ");
            my_str(buffc);
            my_char('\n');
        }else{
            close(fd[1]);
            read(fd[0], buff, SIZE);
            close(fdc[0]);

            my_str("Child: ");
            my_str(buff);
            my_char('\n');

            write(fdc[1], buff, SIZE);
            wait(NULL);
        }
    }else{
        close(fd[0]);

        my_str("Parent: ");
        my_str(the_str);
        my_char('\n');

        write(fd[1],the_str, SIZE);
        wait(NULL);
    }

	//return(0);
}
