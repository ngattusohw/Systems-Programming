#include "list.h"

void traverse_int(Node head) {
    if(!head) return;
    Node temp = head;

    while(temp->next) {
        print_int(temp);
        my_char(' ');
        temp = temp->next;
    }
    print_int(temp);
}
