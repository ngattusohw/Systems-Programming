#include "../../include/my.h"

/*
Same as my_strconcat except:
Copies all of a and then n chars or length of b
 */


char *my_strnconcat(char *a, char *b, int n){
   if(a && b){
		int a_length = my_strlen(a);
		int b_length = n>=0 && (my_strlen(b)>=n) ? n : my_strlen(b);
		char* new_string = (char*) malloc(sizeof(char) * (a_length + b_length));
		
		for(int x=0;x<a_length;x++){
			new_string[x] = a[x];
		}

		int z=0;
		for(int y=a_length;y<(a_length + b_length);y++){
			new_string[y] = b[z];
			z++;
		}
		return new_string;

	}else{
		return NULL;
	}
}