#include <stdio.h>

// NOTES AND EXAMPLES ON MEMORY IN C

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

    // A string's pointer value will always be the first element in
    // the array of chars. This is simply a convention that people
    // came up with

    // Let's finally look at an example:
    char *s = "HI!";
    // `char *s` has been a synonym for `string` this entire time!
    // What this really means is that "`s` is the address of a `char`"

    // We can show that the addresses of each element
    // follows a iterative pattern in memory
    // Also note that all strings's memory address begins
    // with the first element in their array
    printf("String `s` element addresses:\n");
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

    printf("\n");

    // You might be wondering "How the hell did they declare their
    // own `string` type in cs50.h?" Well, turns out you can just
    // use typedef for that:
    typedef char *string;
    // Now `string` is the same thing as saying `char *`. Yippie!

    // We can also use "pointer arithmetic" to replicate what we
    // accomplished above:
    printf("String `s` elements printed with pointer arithmetic:\n");
    printf("%c\n", *s); // Remember that `*s` is simply the memory address of the first char of the string
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
    printf("%c\n", *(s + 3));
}
