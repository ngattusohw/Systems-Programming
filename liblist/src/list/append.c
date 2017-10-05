#include "../../include/list.h"
/*
 Adds a node to the end of a list. DO NOT add a NULL pointer or
 a node with a NULL elem.
 Parse once
*/
void append(struct s_node* node, struct s_node** head){
	if(node && head && node->elem){
		struct s_node* current = head[0];
		struct s_node* hold = current;
		while(current!=NULL){
			hold = current;
			current = current->next;
		}

		hold->next = node;
		node->prev = hold;

	}
}