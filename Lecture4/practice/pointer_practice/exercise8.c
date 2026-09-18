#include <stdio.h>

int main(void) {
    int data[5] = {1, 3, 5, 7, 9};
    int size = sizeof(data) / sizeof(data[0]);
    int *ptr = data;

    printf("1. Subscript notation: %i\n", data[2]);
    printf("2. Pointer notation: %i\n", *(data +2));
    printf("2. Pointer notation: %i\n", *(ptr +2));

    return 0;
}
