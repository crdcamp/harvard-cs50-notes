#include <stdio.h>

void pointer_basics(void);
void strings(void);

int main(void) {
    pointer_basics();
    strings();
}

// Display an introduction to pointers
void pointer_basics(void) {
    printf("POINTER BASICS:\n");
    int n = 50;
    // `*p stores the address of `n` (an integer), not an actual integer
    // `&` is essentially telling the computer "tell me the address of `n`"
    int *p = &n;

    printf("`n`: %i\n", n);
    printf("`n` address: %p\n", &n);

    // Here we're using a dereference operator (*p)
    // This means "go to the address that `p` references
    // and see what you find there"
    printf("`*p`: %i\n", *p);
    printf("`*p` address: %p\n", p);

    printf("\n");
}

void strings(void) {
    printf("STRINGS AND POINTERS:\n");
    // Up until now, the course has obviously been abstracting away
    // strings, as strings aren't a native data type to C

    // You can still use strings, however, but ya gotta work some
    // magic first using pointers

    // Before we do so, remember how we use a nul character to
    // indicate the end of a string. So, a string like "HI!"
    // might look like it's an array of 3 elements at first,
    // but it actually has 4 when accounting for the nul character

    // Essentially, a string is an address of an array of characters
    // that the program must "point" to. The pointer here tells us
    // where the string begins, while `\0` tells us where it ends

    // Let's finally look at an example:
    char s[] = "HI!";

    // We can show that the addresses of each element
    // follow a iterative pattern in memory
    printf("String `s` addresses:\n");
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}
