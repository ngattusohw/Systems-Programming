#include "list.h"

void traverse_char(Node head) {
    if(!head) return;
    Node temp = head;

    while(temp->next) {
        print_char(temp);
        my_char(' ');
        temp = temp->next;
    }
    print_char(temp);
}
