#include "my.h"

/*
Same as my_strcpy except:
Only copies n chars or until the end of src
 */

char* my_strncpy(char *dst, char *src, int n){
	if(dst && src){
		int x;
		for(x=0;x < n && src[x] != '\0';x++){
			dst[x] = src[x];
		}
		dst[x] = '\0';
		return dst;
	}else{
		return dst;
	}
	
}

