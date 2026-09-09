#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// NOTES AND EXAMPLES ON MEMORY IN C

void pointer_basics(void);
void strings(void);
void string_comparisons(void);
int malloc_demo(void);
int malloc_demo_error_check(void);
void garbage_values(void);

int main(void) {
    pointer_basics();
    strings();
    string_comparisons();
    malloc_demo();
    malloc_demo_error_check();
    garbage_values();

    return 0;
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
    // the results from the above array notation:
    printf("String `s` elements printed with pointer arithmetic:\n");
    printf("%c\n", *s); // Remember that `*s` is simply the memory address of the first char of the string
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
    printf("%c\n", *(s + 3));

    // We can further hammer in the fact that strings start with the
    // first character and end with `\0` with the following:
    printf("%s\n", s);
    printf("%s\n", s + 1);
    printf("%s\n", s + 2);
    printf("%s\n", s + 3);

    printf("\n");
}

void string_comparisons(void) {
    printf("STRING COMPARISONS:\n");
    // Let's say we have the following two strings:
    char *s = "HI!";
    char *t = "HI!";

    // We want to compare them to find out if they're
    // the same... but why in the hell wouldn't this work?
    // Wait... this shouldn't work... but I'm almost certain that
    // has something to do with different compilers between my IDE
    // and the course's

    // Anyway, the reason this shouldn't work (and the reason you should never compare strings
    // using just `==`) is because (in the CS50's IDE) `s` and `t` are stored in different
    // locations in the computer's memory. The variables themselves don't contain a string, but the address
    // of the first character of that string.
    // Therefore, both pointers to these addresses contain different identifiers for these pointer chars
    // In other words, `s == t` compares pointers (the memory location), not the contents of the string
    if (s == t) {
        printf("Same\n");
    }
    else {
        printf("Different\n");
    }

    // Let's just continue the example anyway
    if (strcmp(s, t) == 0) {
        printf("Same\n");
    }
    else {
        printf("Different\n");
    }

    // Let's confirm the above notes by determining whether my compiler assigns both pointers
    // to the same address
    printf("`s` pointer address: %p\n", s);
    printf("`t` pointer address: %p\n", t);
    // What do ya know! The addresses are the same!

    printf("\n");
}

int malloc_demo(void) {
    printf("MALLOC OPERATIONS:\n");
    char *s = "hi!";

    // In order to copy this string, we need to copy `s` to somewhere else
    // in memory. Therefore, we need to ask the computer for as much memory
    // as the string `s` takes up (in this case, 4 bytes including the null character)
    // (note that malloc is part of stdlib.h)

    char *t = malloc(strlen(s) + 1); // Allocate 4 bytes of memory to the newly created variable `t` (+1 because of the `nul` character (\0))
    // We're also finally introducing error handling as well
    // Keep in mind that NULL is a specially reserved place in memory at 0
    // meant for things like this
    if (t == NULL) {
        return 1;
    }


    // Now let's copy the contents of `s` into `t`
    for (int i = 0, n = strlen(s); i <= n; i++) { // We use `<=` here since we want to include the null character \0
        t[i] = s[i];
    }

    // Now let's confirm that edits to `t` only apply to `t`
    if (strlen(s) > 0) { // We only would want to convert to upper if there's actually a string to do so with
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // DON'T FORGET TO FREE UP THE MEMORY YOU ALLOCATED!!!
    free(t);

    printf("\n");

    return 0;
}

int malloc_demo_error_check(void) {
    // Memory allocation
    int *x = malloc(3 * sizeof(int));
    // Error checking
    if (x == NULL) {
        return 1;
    }
    // Assigning values to allocated memory
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;

    // NEVER forget to free memory
    free(x);

    return 0;
}

void garbage_values(void) {
    printf("GARBAGE VALUES:\n");

    // So let's say we have a completely empty (and somewhat large)
    // array like this:
    int scores[1024];

    // If we print the values of this empty array, we end up with essentially
    // remnants from the computer's memory that are just left over from
    // other processes
    for (int i = 0; i < 5; i++) {
        printf("%i\n", scores[i]);
    }
}
