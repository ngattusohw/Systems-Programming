#include "/../../include/list.h"
/*
 Allocates and returns a new node with the given pointers. You may
 create nodes with NULLs.
*/
struct s_node* new_node(void* elem, struct s_node* next, struct s_node* previous){
	s_node* the_node = (s_node*) malloc(sizeof(struct s_node));
	the_node->next = next;
	the_node->previous = previous;
	the_node->elem = elem;
	// if(previous!=NULL){
	// 	previous->next = the_node;
	// }
	return the_node;
}