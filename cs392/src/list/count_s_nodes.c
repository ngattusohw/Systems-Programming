#include "list.h"

int count_s_nodes(Node head) {
    int s = 0;
    Node temp = head;

    while(temp) {
        temp = temp->next;
        ++s;
    }

    return s;
}
