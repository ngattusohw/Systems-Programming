#include "my.h"

void my_num_base(int i, char* str){
	/* error if NULL or empty string */
    if(!str || !*str) {
        my_str("\nERR: Expected valid string of length > 0\n");
        return;
    }

    if (i == 0) {
        char c = str[0];
        my_str(&c);
        return;
    }
    /* deal with negative integers */
    unsigned int num = i < 0 ? -i : i;
    if(i < 0) my_char('-');

    /* find the desired radix */
    int radix = 0;
    while(str && str[radix]) radix++;

    if(radix == 1) {
        while(num--) my_char(*str);
        return;
    }

    int exp = 1;
    while(exp <= num/radix) exp *= radix;

    /* print digits in order */
    while(exp) {
        my_char(str[num / exp % radix]);
        exp /= radix;
    }
}


// int main(){
// 	int a = 66;
// 	my_int(a);

// 	return(0);
// }

