#include <stdio.h>

void exercise1(void);
void exercise2(void);
void exercise3(void);
void exercise4(void);
void exercise5(void);
void exercise6(void);
void exercise7(void);

int main(void) {
    //exercise1();

    return 0;
}

void exercise1(void) {
    int var = 42;
    int *ptr;

    ptr = &var;

    printf("Variable `var` value: %i\n", var);
    printf("Variable `var` address: %p\n", &var);
    printf("Pointer 'ptr' address (value of ptr): %p\n", ptr);
    printf("Value accessed via pointer (*ptr): %d\n", *ptr);
}

void exercise2(void) {

}
