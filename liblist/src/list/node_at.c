#include "../../include/list.h"

/*
 Returns a pointer to the node at index n or the last node.
 Parse once
*/
struct s_node* node_at(struct s_node* head, int n){
	if(head){
		struct s_node* hold = head;
		int x=0;
		
		while(hold->next && x<n){
			hold = hold->next;
			x++;
		}

		return hold;

	}else{
		return NULL;
	}
}
