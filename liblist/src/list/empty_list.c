#include "../../include/list.h"
/*
 Frees all the nodes in the list.
 CHALLENGE: Write in two lines (allowed to use other methods in 
 this assignment)
*/
void empty_list(struct s_node** head){
	struct s_node* the_node = *head;
	if(the_node){
		while(the_node){
			struct s_node* the_next = the_node->next;
			the_node->next = NULL;
			the_node->prev = NULL;
			the_node->elem = NULL;
			free(the_node);
			the_node = the_next;
		}
	}
}
