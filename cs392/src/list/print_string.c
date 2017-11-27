#include "list.h"

void print_string(Node node) {
    if(node && node->elem)
        my_str((char *) node->elem);
}
