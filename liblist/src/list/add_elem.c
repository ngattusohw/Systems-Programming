#include "../../include/list.h"

/* 
 Creates a new node with elem and adds it to head. DO NOT add a NULL 
 elem.
 DOES NOT PARSE
*/
void add_elem(void* elem, struct s_node** head){
	if(elem && head){
		struct s_node* the_node = (struct s_node*) malloc(sizeof(struct s_node));
		the_node->elem = elem;
		the_node->prev = NULL;
		the_node->next = (*head)->next;
		the_node = (*head);
	}
}
