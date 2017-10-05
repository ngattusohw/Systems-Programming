#include "../../include/list.h"
/*
 Removes the node at index n or the last node.
 Parse once
*/
void* remove_node_at(struct s_node** head, int n){
	if(head && *head){
		struct s_node* hold = *head;
		int x=0;
		
		while(hold->next && x<n){
			hold = hold->next;
			x++;
		}

		return remove_node(&hold);
	}else{
		return NULL;
	}

}