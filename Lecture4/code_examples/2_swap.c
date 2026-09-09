#include <stdio.h>

void swap(int a, int b);
void swap_fixed(int *a, int *b);

int main (void) {
    int x = 1;
    int y = 2;

    printf("BROKEN FUNCTION RESULTS:\n");
    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x, y);

    printf("\n");

    printf("FIXED FUNCTION RESULTS:\n");
    printf("x is %i, y is %i\n", x, y);
    // You need to pass in the addresses of `x` and `y` using `&`
    swap_fixed(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

// This won't work as intended due to function scope
// You're passing copies of `x` and `y` to this function,
// not the literal values themselves
// This is called "passing by value"
void swap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// What we want to do is "pass by reference"
// This involves using pointers to directly target
// the memory addresses of the variables being passed
// into the function, rather than working with copies of
// the variables
void swap_fixed(int *a, int *b) { // The address of int a and the address of int b!
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
