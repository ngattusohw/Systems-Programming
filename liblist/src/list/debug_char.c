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
			if(hold->prev ==NULL && hold->next==NULL){
				prev = "(NULL ";
				next = "NULL), ";
			}else if(hold->prev == NULL && hold->next!=NULL){
				prev = "(NULL ";
				next = my_strconcat((char*) hold->next->elem,"), ");
			}else if(hold->next == NULL && hold->prev!=NULL){
				next = "NULL), ";
				prev = my_strconcat("(",(char*) hold->prev->elem);
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
