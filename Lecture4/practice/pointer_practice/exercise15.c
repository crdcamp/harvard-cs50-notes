#include <stdio.h>
#include <stdlib.h>

// Dynamically allocate memory for a single integer using malloc().
// Store the value 108 in this allocated memory, print the value and its
// memory address, and then free the memory using free().

int main(void) {
    int integer = 108;
    // Allocate memory for the integer
    int *integer_p = malloc(sizeof(integer));
    // Assign the integer to the allocated memory
    *integer_p = integer;

    printf("Original integer memory location: %p\n", &integer);
    printf("Original integer value: %i\n", integer);
    printf("\n");
    printf("Pointer integer memory location: %p\n", &integer_p);
    printf("Original integer value: %i\n", *integer_p);

    // Free allocated memory
    free(integer_p);
}
