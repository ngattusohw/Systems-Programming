#include "list.h"

void add_node(Node node, Node *head) {
    if(!node || !node->elem) return;

    node->prev = NULL;

    if(!head) {
        head = &node;
        return;
    }

    if(!*head) {
        *head = node;
        return;
    }

    node->next = *head;
    (*head)->prev = node;
    *head = node;
}

