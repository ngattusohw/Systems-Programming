#include "../include/my.h"
#include <string.h>
#include <stdio.h>

int main(){
	char **strings = (char**)malloc(5*sizeof(char*));
    int i = 0;
    for(i = 0; i < 5; i++){
        //printf("%d\n", i);
        strings[i] = (char*)malloc(50*sizeof(char));
    }
    //assign them all something
    sprintf(strings[0], "bird goes tweet");
    sprintf(strings[1], "mouse goes squeak");
    sprintf(strings[2], "cow goes moo");
    sprintf(strings[3], "frog goes croak");
    strings[5] = NULL;


	printf("Printing the total:: %s\n", my_vect2str(strings));

	return(0);
}
