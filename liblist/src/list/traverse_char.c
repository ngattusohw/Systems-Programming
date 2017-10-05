#include "../../include/list.h"
/*
 Prints all the elems as chars separated by a space
*/
void traverse_char(struct s_node* head){
	if(head){
		struct s_node* hold = head;
		
		while(hold){
			my_char((char) hold->elem);
			hold = hold->next;
		}
	}
}
