#include "../../include/my.h"

void my_num_base(int i, char* str){
	if(!str || !*str){
		my_str("\nNot a valid string");
		return;
	}else if(i == 0){
		my_char(*str);
		return;
	}else{
		unsigned int num = i < 0 ? -i : i;
		if(i<0){
			my_char('-');
		}

		int counter = 0;
		while(str && str[counter]){
			counter++;
		}

		if(counter == 1){
			while(num--){
				my_char(*str);
			}
			return;
		}

		int ex = 1;
		while(ex <= num/counter){
			ex *= counter;
		}

		while(ex){
			my_char(str[num / ex % counter]);
			ex /= counter;
		}
	}
}


// int main(){
// 	int a = 66;
// 	my_int(a);

// 	return(0);
// }