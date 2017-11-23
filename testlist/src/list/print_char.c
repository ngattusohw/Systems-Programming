#include "list.h"

void print_char(Node node) {
    if(node && node->elem)
        my_char(*((char *) node->elem));
}
