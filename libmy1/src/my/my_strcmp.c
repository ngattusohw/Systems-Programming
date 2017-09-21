#include "../../include/my.h"

/*
Compares strings by ascii value
 If a and b are identical, return 0. 
 if a < b, return negative number 
 if a > b, return positive number
 Two NULL are equal.
 NULL is always less than a normal string
*/


int my_strcmp(char* a, char* b){
	int total_a = 0;
	int total_b = 0;
	if(a && b){
		for(int x=0;x<my_strlen(a);x++){
			total_a += a[x];
		}

		for(int y=0;y<my_strlen(b);y++){
			total_b+= b[y];
		}

		if(a==b){
			return 0;
		}else if(a>b){
			return total_a;
		}else if(a<b){
			return total_b * -1;
		}
	}else if(a==NULL && b==NULL){
		return 0;
	}else if(a!=NULL){
		return 1;
	}

	return -1;	
}
