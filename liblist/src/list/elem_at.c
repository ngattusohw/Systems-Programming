#include "../../include/list.h"
/*
 Returns a pointer to the elem at index n or the last node.
 Parse once.
*/
void* elem_at(struct s_node* head, int n){
	if(head){
		struct s_node* hold = head;
		int x=0;
		
		while(hold->next && x<n){
			hold = hold->next;
			x++;
		}
		
		return hold->elem;

	}else{
		return NULL;
	}
}