#include "list.h"

void empty_list(Node *head) {
    while(head && *head) 
        remove_node(head);
}
