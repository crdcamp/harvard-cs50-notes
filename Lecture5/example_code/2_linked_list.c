#include <stdio.h>
#include <stdlib.h>

int og_example(void);
int append_example(void);

typedef struct node {
    int number;
    struct node *next;
} node;

int main(void) {
    og_example();
    append_example();
}

int og_example(void) {
    printf("OG EXAMPLE\n");
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

    // Now let's print the numbers
    node *ptr = list;
    printf("WHILE LOOP RESULTS:\n");
    while (ptr != NULL) {
        printf("Number:  %i\n", ptr->number);
        printf("Address: %p\n", ptr->next);
        ptr = ptr->next;
    }

    printf("\n\n");

    // I definitely prefer (as most would) the while loop, but here's how you could
    // do it with a for loop. Helps paint the picture a bit more as well.
    printf("FOR LOOP RESULTS:\n");
    for (node *ptr = list; ptr != NULL; ptr = ptr->next) {
        printf("Number:  %i\n", ptr->number);
        printf("Address: %p\n", ptr->next);
    }

    // Free memory
    while (ptr != NULL) {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    printf("\n\n");

    return 0;
}

// Now that we've created a linked list and printed it, we want to start thinking
// about how we'd go about editing it. We want to be able to:
// - Prepend
// - Append
// - Inserting a new node (number) at a desired place in the list
int append_example(void) {
    printf("APPEND EXAMPLE\n");
    node *list = NULL;

    for (int i = 0; i < 3; i++) {
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            return 1;
        }

        n->number = i + 1; // Assign an `int` to `number`
        n->next = NULL; // Mostly a safety precaution at this point
        n->next = list; // Assign `list`'s address to `next`
        list = n; // Assign `n`'s address to `list`

        // APPEND A VALUE
        // If the list is empty, then we can simply make it `n`
        if (list == NULL) {
            list = n;
        }
        else {
            // Iterate over nodes in list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next) {
                // If at end of list
                if (ptr->next == NULL) {
                    // Append node
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    // Print results
    node *ptr = list;
    while (ptr != NULL) {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    // Free memory
    while (ptr != NULL) {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    printf("\n\n");

    return 0;
}
