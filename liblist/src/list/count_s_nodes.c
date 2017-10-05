#include "../../include/list.h"
/*
 Returns the value the length of the list
 Parse Once.
*/
int count_s_nodes(struct s_node* head){
	int count = 0;

	if(head){
		count++;
		struct s_node* hold = head->next;
		while(hold){
			count++;
			hold=hold->next;
		}
	}

	return count;
}