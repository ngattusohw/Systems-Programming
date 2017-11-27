#include "list.h"

void print_int(Node node) {
    if(node && node->elem) {
        my_int((int) *((int *) node->elem));
    }
}
