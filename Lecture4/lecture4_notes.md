[Lecture Video](https://www.youtube.com/watch?v=db0H0U13YsA&t=63s)
[Problem Set 4]()

# Memory

We begin the lecture with the following example:

```c
#include <stdio.h>

int main(void) {
    int n = 50;
    // `*p stores the address of `n` (an integer), not an actual integer
    // `&` is essentially telling the computer "tell me the address of `n`"
    int *p = &n;

    printf("n: %i\n", n);
    printf("n address: %p\n", &n);

    printf("*p: %i\n", *p);
    printf("*p address: %p\n", p);
}
```
