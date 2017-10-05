#include "../../include/list.h"
/*
 Prints the elem of node as a char
*/
void print_char(struct s_node* node){
	if(node && node->elem){
		my_char((char) node->elem);
	}
}