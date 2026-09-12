#include <stdio.h>

void increment(int *a);

// Create a function increment_value that takes an integer
// pointer as an argument and increments the value of the
// variable it points to by one. Demonstrate the change in
//the main function.
int main(void) {
    int count = 10;
    printf("Before function call: %i\n", count);

    increment(&count);
    printf("After function call: %i\n", count);

    return 0;
}

void increment(int *a) {
    // `()` forces the dereference to happen first
    (*a)++;
}
