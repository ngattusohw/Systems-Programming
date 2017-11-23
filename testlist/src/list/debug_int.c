#include "list.h"

static void fprint_int(Node node) {
    if(node)
        print_int(node);
    else
        my_str("NULL");
}

void debug_int(Node head) {
    if(!head) return;

    Node temp = head;

    /* print first */
    my_str("(NULL <- ");
    fprint_int(temp);
    my_str(" -> ");
    fprint_int(temp->next);
    my_str(")");

    while(temp->next) {
        temp = temp->next;
        my_str(", (");
        fprint_int(temp->prev);
        my_str(" <- ");
        fprint_int(temp);
        my_str(" -> ");
        fprint_int(temp->next);
        my_str(")");
    }
}
