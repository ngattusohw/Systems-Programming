#include "../../include/list.h"
/*
 Removes the last node from the list.
 Parse Once.
*/


void* remove_last(struct s_node** node){
	if(node){
		struct s_node* Node = *node;
		struct s_node* next = Node->next;
		while(next){
			Node = next;
			next = next->next;
		}

		return remove_node(&Node);		

	}else{
		return NULL;
	}
}