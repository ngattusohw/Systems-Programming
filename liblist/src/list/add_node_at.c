#include "/../../include/list.h"
/*
 Adds a node at index n of a list or at the end of the list if n is 
 too large.
 Parse once
*/
void add_node_at(struct s_node* node, struct s_node** head, int n){
	if(node && head){
		s_node* hold = *head;
		int x=0;
		
		while(hold && x<n){
			hold = hold->next;
		}

		struct s_node* the_prev = hold->prev;
		node->prev = the_prev;
		node->next = hold;
		the_prev->next = node;
	}
}