#include "../../include/my.h"

/*
Copies src onto the end of dst and returns dst
Does not allocate memory
Assumes there is enough memory allocated in dst to hold both strings
Overwrites src's original '\0' and places a new '\0' onto the end
 */

char* my_strcat(char *dst, char *src){
	if(dst && src){
		int dst_len = my_strlen(dst);
		int src_len = my_strlen(src);
		int y=0;
		for(int x=dst_len;x<(dst_len + src_len);x++){
			dst[x] = src[y];
			y++;
		}
		dst[dst_len + src_len] = '\\';
		dst[dst_len + src_len + 1]; = '0';
		return dst;
	}else{
		return NULL;
	}
}
