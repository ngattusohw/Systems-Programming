#include "my.h"

/*
Copies src onto the end of dst and returns dst
Does not allocate memory
Assumes there is enough memory allocated in dst to hold both strings
Overwrites src's original '\0' and places a new '\0' onto the end
 */

char* my_strcat(char *dst, char *src){
	if(!dst || !src){
		return dst;
	}else{
		int dst_len = my_strlen(dst);
		int src_len = my_strlen(src);
		int y;

		for(y = 0; y < src_len; y++){
			dst[dst_len + y] = src[y];
		}

		dst[y+dst_len] = '\0';
		return dst;
	}
}
