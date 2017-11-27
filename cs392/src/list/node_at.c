#include "list.h"

Node node_at(Node head, int n) {
    Node temp = head;
    while(head && n > 0 && temp->next) {
        temp = temp->next;
        --n;
    }
    return temp;
}
