#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} node;

int main(void) {
    // Create an empty list
    node *list = NULL; // The list points to nothing

    for (int i = 0; i < 3; i++) {
        // First we need to allocate a new node
        // Create one new node, store a value in it, and then point the list at the node
        node *n = malloc(sizeof(node)); // Allocate space for the size of the node (we use node * because we want to point to the memory of an actual node)
        if (n == NULL) {
            return 1;
        }
        // Go to the address of n, go inside that node, and store a value
        // (previously we used (*n).number instead of n->number)
        // The ()s are used because of precedence. You need to dereference `n`
        // before you actually access the value.
        n->number = i;
        n->next = NULL;
    }
}
