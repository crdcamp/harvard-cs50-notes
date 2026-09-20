#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} node;

int main(void) {
    // Create an empty list
    // The list points to nothing (just to initiate the list so we can then use it in the following loop)
    node *list = NULL;

    for (int i = 0; i < 3; i++) {
        // First we need to allocate memory for a new node
        // Allocate space for the size of a new node (we use `node *` because we want to point to the memory of an actual node)
        // EVERY TIME YOU CALL MALLOC ITS ASSIGNING A NEW MEMORY LOCATION, so.....
        // that's why we can just keep reusing `n` here, as `malloc` has this implicit behavior\

        // Also remember that `malloc` returns the address of the first byte of the block of memory,
        // So, just always interpret `*n` as a memory address (this is important further down)
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            return 1;
        }

        // Go to the address of n, go inside that node, and store a value in `number`
        // (previously we used `(*n).number` instead of `n->number` which is what the next line is referring to)
        // The ()s are used because of precedence. You need to dereference `n` before you actually access the value.
        n->number = i + 1; // Note that `i++` wouldn't work here and would instead actually edit the original `i`
        n->next = NULL; // Unnecessary line since in the next line you're already effectively doing this in the first iteration (probably best to leave it like this though)

        // PREPEND node to list: We're setting this up in a way that the memory can be traced backwards (like a mf trail of breadcrumbs)
        // This way NULL ends up being at the end of the linked list, thus giving us a way
        // (similar to how `\0` does in a string) to determine that we've reached the end of the list
        // We're essentially updating `next` for the next iteration so we can "backtrack" later
        n->next = list; // Assign the address of `list` to `n`

        // When the looping is finished, this is essentially our
        // entry point for accessing the list
        list = n; // Assign the address of `n` to `list`
    }

    // Now let's print the numbers (also demonstrates how you can access values in the list)
    node *ptr = list;
    printf("WHILE LOOP RESULTS:\n");
    while (ptr != NULL) {
        printf("Number:  %i\n", ptr->number);
        printf("Address: %p\n", ptr->next);
        ptr = ptr->next;
    }

    printf("\n\n");

    // I definitely prefer (as most would) the while loop, but here's how you could
    // do it with a for loop. Help paint the picture a bit more as well.
    printf("FOR LOOP RESULTS:\n");
    for (node *ptr = list; ptr != NULL; ptr = ptr->next) {
        printf("Number:  %i\n", ptr->number);
        printf("Address: %p\n", ptr->next);
    }

    return 0;
}
