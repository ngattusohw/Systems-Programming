#include "list.h"

void *remove_node(Node *node) {
    if(!node || !*node) return NULL;

    Node temp = *node;
    void *elem = temp->elem;

    *node = NULL;

    if(temp->next)
        temp->next->prev = temp->prev;

    if(temp->prev)
        temp->prev->next = temp->next;
    else
        *node = temp->next ? temp->next : NULL;

    free(temp);
    return elem;
}
