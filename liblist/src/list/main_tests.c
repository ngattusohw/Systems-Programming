#include "my.h"
#include "list.h"
#include <string.h>
#include <stdio.h>

int main(){
	
	struct s_node* Node = new_node("Hi",NULL,NULL);

	//printf(elem_at(Node,0));
	
	struct s_node** the_list = (struct s_node**) malloc(sizeof(struct s_node) * 4);
	add_node(Node,the_list);

	return(0);
}