#include "../../include/list.h"

/* 
 Creates a new node with elem and adds it to head. DO NOT add a NULL 
 elem.
 DOES NOT PARSE
*/
void add_elem(void* elem, struct s_node** head){
	if(elem && head){
		struct s_node* the_node = (s_node*) malloc(sizeof(struct s_node));
		the_node->elem = elem;
		the_node->prev = head;
		head->next = head;

	}
}