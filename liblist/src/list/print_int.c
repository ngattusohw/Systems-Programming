#include "../../include/list.h"
/*
 Prints the elem of node as a in
*/
void print_int(struct s_node* node){
	if(node && node->elem){
		my_int(*((int*)node->elem));
		my_str("\n");
	}
}
