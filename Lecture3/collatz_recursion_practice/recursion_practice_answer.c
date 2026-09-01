#include <stdio.h>
// Video: https://www.youtube.com/watch?v=mz6tAJMVmfM&time_continue=755&source_ve_path=NzY3NTg&embeds_widget_referrer=https%3A%2F%2Fcs50.harvard.edu%2F&embeds_referring_euri=https%3A%2F%2Fvideo.cs50.io%2F&embeds_referring_origin=https%3A%2F%2Fvideo.cs50.io
// You were really close! This is good! Don't freak out!

// Based on your attempt, you're probably wondering
// why we're adding 1 before sending `n` to `collatz`
// This is because

int collatz(int n);

int main(void) {
    int evenTest = collatz(24);
    printf("Even result: %i\n", evenTest);

    int oddTest = collatz(27);
    printf("Odd result: %i\n", oddTest);
}

int collatz(int n) {
    // Base case
    if (n == 1)
        return 0;
    // Even numbers
    else if ((n % 2) == 0)
        return 1 + collatz(n / 2);
    // Odd numbers
    else
        return 1 + collatz(3*n + 1);
}
