#include "../../include/list.h"
/*
 Prints all the elems as ints separated by a space
*/
void traverse_int(struct s_node* head){
	if(head){
		struct s_node* hold = head;
		
		while(hold){
			my_int((int) hold->elem);
			hold = hold->next;
		}
	}

}
