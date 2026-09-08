#include <stdio.h>

int main(void) {
    int n = 50;
    printf("Original `n` address: %p\n", &n);
    // `*p stores the address of `n` (an integer), not an actual integer
    // `&` is essentially telling the computer "tell me the address of `n`"
    int *p = &n;

    printf("n: %i\n", n);
    printf("n address: %p\n", &n);

    // Here we're using a dereference operator (*p)
    // This means "go to the address that `p` references"
    printf("*p: %i\n", *p);
    printf("*p address: %p\n", p);



}
