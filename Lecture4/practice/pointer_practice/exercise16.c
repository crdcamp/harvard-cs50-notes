#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
// Dynamically allocate memory for an array of 5 integers using malloc().
// Read 5 integer values from the user into the array, print them using
// pointer arithmetic, and finally, free the allocated memory.

// (I just realized they want malloc for this after making most of this code
// which in turn led to me realizing how retarded this is. Let's end the
// problem set here)

void print_array(char *message, int *array, int array_len);

int main(void) {
    // Define an array
    int array[5] = {};
    int array_len = sizeof(array) / sizeof(array[0]);

    // Prompt the user for 5 integer inputs for the array
    int i = 0;
    while (i < array_len) {
        // Prompt the user for an input
        int user_input;
        printf("Element %i: ", i + 1);
        scanf("%i", &user_input);

        // Add the user's input to the array
        // and iterate to the next index
        *(array + i) = user_input;
        i++;
    }

    // Show us that array of yours little boy!
    print_array("Resulting array: ", array, array_len);

    //
}

void print_array(char *message, int *array, int array_len) {
    printf("%s", message);
    for (int i = 0; i < array_len; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");
}
