#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
// THIS IS ALL A PRECURSOR TO `linked_list.c`
void print_int_array(char *message, int *array, int array_len);

int main(void) {
    // Here we're pointing malloc to an int variable called list
    // that will store 3 ints
    int *list = malloc(3 * sizeof(int));  // Malloc returns the address of the first byte

    // Check if we try to access unavailable memory
    if (list == NULL) {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Now let's say some time has passed, and that we want to
    // append a new number to `list`
    // We'd need to create a new entry through the use of a
    // temporary variable
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL) {
        return 1;
        // If you encounter an error, you'd ideally want to
        // give back memory to ze computer
        free(list);
    }
    // Copy old list into new list
    for (int i = 0; i < 3; i++) {
        tmp[i] = list[i]; // REMEMBER... arrays are pointers! This is why you don't need to use pointers here silly goose
    }
    tmp[3] = 4; // Assign new value

    // Free the first list and reassign
   // the new list
    free(list);
    list = tmp;
    free(list);

    return 0;
}

void print_int_array(char *message, int *array, int array_len) {
    printf("%s", message);
    for (int i = 0; i < array_len; i++) {
        printf("%i", array[i]);
    }
    printf("\n");
}
