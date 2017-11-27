#include "list.h"

void add_node_at(Node node, Node *head, int n) {
    if(!node || !node->elem) return;
    
    if(!head || !*head || n <= 0) {
        add_node(node, head);
        return;
    }

    Node temp = *head;
    while(n > 0 && temp->next) {
        temp = temp->next;
        --n;
    }

    if(n == 0) {
        node->prev = temp->prev;
        temp->prev = node;
        node->next = temp;
        node->prev->next = node;
    } else {
        temp->next = node;
        node->prev = temp;
        node->next = NULL;
    }
}

