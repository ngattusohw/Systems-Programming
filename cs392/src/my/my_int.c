#include "my.h"

void my_int(int i){
	if(i == 0){
		my_str("0");
	}else{
		my_num_base(i, "0123456789");
	}
}
