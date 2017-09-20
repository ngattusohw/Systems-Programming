#include "../../include/my.h"

/*
	Same as my_strcmp except:
 Only compares n chars or until the end of a string
 */

int my_strncmp(char*a, char *b, int n){
	int length_a = n > my_strlen(a) ? my_strlen(a) : n;
	int length_b = n > my_strlen(b) ? my_strlen(b) : n;

    int total_a = 0;
	int total_b = 0;
	if(a && b){
		for(int x=0;x<length_a;x++){
			total_a+=a;
		}

		for(int y=0;y<length_b;y++){
			total_b+=b;
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