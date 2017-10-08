#include "../../include/my.h"

/*
Same as my_strcpy except:
Only copies n chars or until the end of src
 */

char* my_strncpy(char *dst, char *src, int n){
	if(dst && src && n>=0){
		int dst_len = my_strlen(dst);
		int src_len = my_strlen(src);
		for(int x=0;x<n && x<src_len && x<dst_len;x++){
			dst[x] = src[x];
		}
		return dst;
	}else{
		return NULL;
	}
	
}

