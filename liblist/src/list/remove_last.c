#include "/../../include/list.h"
/*
 Removes the last node from the list.
 Parse Once.
*/


void* remove_last(struct s_node** node){
	if(node){
		s_node* Node = *node;
		s_node* next = Node->next;
		while(next){
			Node = next;
			next = next->next;
		}

		return remove_node(Node);		

	}	
}