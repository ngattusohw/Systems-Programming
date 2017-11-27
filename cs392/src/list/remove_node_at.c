#include "list.h"

void *remove_node_at(Node *head, int n) {
    if(!head || !*head) return NULL;

    while(*head && (*head)->next && n-- > 0)
        head = &(*head)->next;

    return remove_node(head);
}
