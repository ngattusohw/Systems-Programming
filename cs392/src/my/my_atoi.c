#include "my.h"

/*
Returns the int represented by the ascii string
Handles negatives.
Ignores preceding characters and trailing numbers and chars
Examples:
"5" => 5
"-5" => -5
"--5" => 5
"a-b54sc7-d" => -54
"abcd" => 0

Between 48 and 57
 */

int my_atoi(char* str){
	if(str){
		int flip_flop = 1;
		char the_num[my_strlen(str)];
		the_num[0] = 0;
		for(int x=0;x<my_strlen(str);x++){
			int c = (int) str[x];
			if(c == 45){
				flip_flop*=-1;
			}else if(c>=48 && c<=57){
				for(int y=0;c>=48 && c<=57;y++){
					the_num[y] = (char) c;
					x++;
					c = (int) str[x];
				}
				return (atoi(the_num) * (flip_flop == 1 ? 1 : -1));
			}
		}
		return 0;
	}else{
		return 0;
	}
}

