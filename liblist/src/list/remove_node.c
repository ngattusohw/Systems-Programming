#include "/../../include/list.h"
/* 
 Removes the given node from the list. Returns elem and frees the 
 node from memory.
 DOES NOT PARSE.
*/
void* remove_node(struct s_node** node){
	if(node){
		void* elem = node->elem;
		s_node* previous = node->previous;
		s_node* next = node->next;

		if(previous && next){
			previous->next = next;
			next->prev = previous;
		}

		free(node);
		return elem;
	}
}