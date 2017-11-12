#include "my.h"
#include "list.h"
#include <string.h>
#include <stdio.h>

int main(){
	int x=120;
	void* pointer = &x;
	struct s_node* Node = new_node(pointer,NULL,NULL);

	//printf("%d\n",(*(int *) elem_at(Node,0)));
	
	struct s_node** the_list = (struct s_node**) malloc(sizeof(struct s_node) * 4);
	add_node(Node,the_list);
	//print_int(Node);
	
	int y=121;
	void* pointer2 = &y;
	struct s_node* whatsup = new_node(pointer2,NULL,Node);
	add_node(whatsup,the_list);

	traverse_int(Node);

	return(0);
}
