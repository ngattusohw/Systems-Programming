#include "../../include/list.h"
/*
 Prints all the elems as strings separated by a space in the format
 (NULL <- Elem -> Next elem), ..., (Previous elem <- Elem -> NULL) 
*/
void debug_string(struct s_node* head){
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
				prev = my_strconcat("(",(char*) hold->prev->elem);
				next = my_strconcat((char*) hold->next->elem,"), ");
			}
			char* the_string1 = my_strconcat(prev," <- ");
			char* the_string2 = my_strconcat(my_strconcat((char*) hold->elem," -> "),next);
			my_str(my_strconcat(the_string1,the_string2));

			hold=hold->next;
		}
	}else{
		char* the_str = "NULL <- NULL -> NULL";
		my_str(the_str);
	}
}