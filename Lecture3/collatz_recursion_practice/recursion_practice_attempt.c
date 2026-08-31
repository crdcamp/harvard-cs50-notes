#include <stdio.h>
// Video: https://www.youtube.com/watch?v=mz6tAJMVmfM&time_continue=755&source_ve_path=NzY3NTg&embeds_widget_referrer=https%3A%2F%2Fcs50.harvard.edu%2F&embeds_referring_euri=https%3A%2F%2Fvideo.cs50.io%2F&embeds_referring_origin=https%3A%2F%2Fvideo.cs50.io

// The Collatz conjecture applies to positive integers and
// speculates that it is always possible to get
// "back to 1" if you follow these steps:

// If `n` is 1, stop (base case)
// Otherwise, if `n` is even, repeat this process on `n`/2 (first recursion func)
// Otherwise, if `n` is odd, repeat this process on 3n + 1 (second recursion func)

// Write a recursive function `collatz(n)` that calculates how
// many steps it takes to get to 1 if you start from `n` and
// recurse as indicated above

// 11:06

int collatz(int n);

int main(void) {
    int evenResult = collatz(24);
    printf("Even result: %i\n", evenResult);

    int oddResult = collatz(27);
    printf("Odd result: %i\n", oddResult);
}

int collatz(int n) {
    // If `n` is 1, stop
    if (n == 1) {
        return 0;
    }
    // Otherwise, if `n` is even, repeat `n` / 2
    else if (n % 2 == 0) {
        return collatz(n / 2);
    }
    // Otherwise, if `n` is odd, repeat 3n + 1
    else
        return collatz(3*n + 1);
}
