#include "list.h"

void *elem_at(Node head, int n) {
    if(!head) return NULL;
    return node_at(head, n)->elem;
}
