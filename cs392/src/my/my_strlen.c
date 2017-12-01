#include "my.h"

//returns the size of a character array using a pointer to the first element of the character array
int my_strlen(char *str){
	// if(ptr){
	//     int offset = 0;
	//     int count = 0;
	//     while(*(ptr + offset) != '\0'){
	//         count++;
	//         offset++;
	//     }
	//     return count;
	// }else{
	// 	return -1;
	// }
	int len = -1;
    if(str) {
        for(len = 0; *str; str++) {
            len++;
        }
    }
    return len;
}

