#include <stdio.h>
// Find out what error you get when you
// try to change a constant
int main(void) {
    const int a = 1;
    printf("a: %i\n", a);

    a = 2;
}
