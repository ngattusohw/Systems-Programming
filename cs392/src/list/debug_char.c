#include "list.h"

static void fprint_char(Node node) {
    if(node)
        print_char(node);
    else
        my_str("NULL");
}

void debug_char(Node head) {
    if(!head) return;

    Node temp = head;

    /* print first */
    my_str("(NULL <- ");
    fprint_char(temp);
    my_str(" -> ");
    fprint_char(temp->next);
    my_str(")");

    while(temp->next) {
        temp = temp->next;
        my_str(", (");
        fprint_char(temp->prev);
        my_str(" <- ");
        fprint_char(temp);
        my_str(" -> ");
        fprint_char(temp->next);
        my_str(")");
    }
}
