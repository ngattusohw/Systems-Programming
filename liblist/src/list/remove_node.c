#include "../../include/list.h"
/* 
 Removes the given node from the list. Returns elem and frees the 
 node from memory.
 DOES NOT PARSE.
*/
void* remove_node(struct s_node** node){
	if(*node){
		if((*node)->prev){
			//this is not the head
			struct s_node* the_node = *node;
			void* elem = the_node->elem;
			struct s_node* previous = the_node->prev;
			struct s_node* next = the_node->next;

			if(previous && next){
				previous->next = next;
				next->prev = previous;
			}

			free(the_node);
			return elem;
		}else{
			//this is the head
			if((*node)->next){
				(*node)->next->prev = NULL;
				free((*node));
				return (*node)->elem;
			}else{
				free((*node));
				return (*node)->elem;
			}
		}
	}else{
		return NULL;
	}
}