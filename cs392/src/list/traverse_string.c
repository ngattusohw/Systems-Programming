#include "list.h"

void traverse_string(Node head) {
    if(!head) return;
    Node temp = head;

    while(temp->next) {
        print_string(temp);
        my_char(' ');
        temp = temp->next;
    }
    print_string(temp);
}
