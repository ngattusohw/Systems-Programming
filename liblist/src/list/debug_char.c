#include "../../include/list.h"
/*
 Prints all the elems as chars separated by a space in the format
 (NULL <- Elem -> Next elem), ..., (Previous elem <- Elem -> NULL) 
*/
void debug_char(struct s_node* head){
	if(head){
		struct s_node* hold = head;
		while(hold){
			char* prev;
			char* next;
			if(hold->prev == NULL){
				prev = "(NULL ";
			}else if(hold->next == NULL){
				next = "NULL), ";
			}else{
				prev = "(" + hold->prev->elem;
				next = hold->next->elem + "), ";
			}
			char* the_string = prev + " <- " + hold->elem + " -> " + next;
			my_str(the_string);

			hold=hold->next;
		}
	}else{
		char* the_str = "NULL <- NULL -> NULL";
		my_str(the_str);
	}
}