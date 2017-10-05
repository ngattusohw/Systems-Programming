#include "../../include/list.h"
/*
 Prints all the elems as strings separated by a space
*/
void traverse_string(struct s_node* head){
	if(head){
		struct s_node* hold = head;
		
		while(hold){
			my_str((char *) hold->elem);
			hold = hold->next;
		}
	}
}