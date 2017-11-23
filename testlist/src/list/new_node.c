#include "list.h"

Node new_node(void *elem, Node next, Node prev) {
    Node node = (Node) malloc(NODE_SIZE);
    node->elem = elem;
    node->next = next;
    node->prev = prev;

    if(prev)
        prev->next = node;
    if(next)
        next->prev = node;

    return node;
}
