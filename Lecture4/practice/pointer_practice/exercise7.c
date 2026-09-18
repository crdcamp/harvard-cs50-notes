#include <stdio.h>

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *p = arr;

    printf("Array elements using pointer arithmetic:\n");

    for (int i = 0; i < size; i++) {
        printf("Element %d: %d\n", i, *(p + i));
    }

    return 0;
}
