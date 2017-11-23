#include "list.h"

static void fprint_string(Node node) {
    if(node)
        print_string(node);
    else
        my_str("NULL");
}

void debug_string(Node head) {
    if(!head) return;

    Node temp = head;

    /* print first */
    my_str("(NULL <- ");
    fprint_string(temp);
    my_str(" -> ");
    fprint_string(temp->next);
    my_str(")");

    while(temp->next) {
        temp = temp->next;
        my_str(", (");
        fprint_string(temp->prev);
        my_str(" <- ");
        fprint_string(temp);
        my_str(" -> ");
        fprint_string(temp->next);
        my_str(")");
    }
}
