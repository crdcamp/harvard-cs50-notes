#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} node;

int main(void) {
    // Create an empty list (essentially synonymous with a "dynamic array")
    node *list = NULL; // The list points to nothing (just to initiate the list)

    for (int i = 0; i < 3; i++) {
        // First we need to allocate a new node
        // Create one new node, store a value in it, and then point the list at the node
        // Allocate space for the size of a new node (we use `node *` because we want to point to the memory of an actual node)
        // EVERY TIME YOU CALL MALLOC ITS ASSIGNING A NEW MEMORY LOCATION, so.....
        // that's why we can just keep reusing `n` here as `malloc` has this implicit behavior
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            return 1;
        }

        // Go to the address of n, go inside that node, and store a value
        // (previously we used `(*n).number` instead of `n->number` which is what the next 2 lines are referring to)
        // The ()s are used because of precedence. You need to dereference `n`
        // before you actually access the value.
        n->number = i++;
        n->next = NULL;

        // PREPEND node to list
        // This way NULL ends up being at the end of the linked list,
        // thus giving us a way (similar to `\0` does) to determine that
        // we've reached the end of the list
        // Assign the address of `list` to `n`
        // We're essentially updating `next` for the next iteration
        n->next = list;
        // Assign the address of `n` to `list`
        // When the looping is finished, this is essentially our
        // entry point for accessing the list
        list = n;
    }
    return 0;
}
