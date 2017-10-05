#include "../../include/list.h"
#include <stdio.h>

/*
 Inserts a node at the start of the list. DO NOT add a NULL pointer or
 a node with a NULL elem.
 DOES NOT PARSE
*/
void add_node(struct s_node* node, struct s_node** head){
	struct s_node* the_node = *head;
	
	if(the_node && node && node->elem){

		node->next = the_node;
		node->prev = NULL;
		the_node->prev = node;
	}
}
