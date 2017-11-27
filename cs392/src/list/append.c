#include "list.h"

void append(Node node, Node *head) {
    if(!node || !node->elem)
        return;
    if(!head || !*head) {
        add_node(node, head);
        return;
    }

    Node temp = *head;
    while(temp->next)
        temp = temp->next;

    temp->next = node;
    node->prev = temp;
}
