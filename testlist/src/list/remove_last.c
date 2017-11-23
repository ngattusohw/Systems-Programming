#include "list.h"

void *remove_last(Node *node) {
    return remove_node_at(node, 2147483647);
}
