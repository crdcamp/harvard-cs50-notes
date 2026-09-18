#include <stdio.h>

void print_elements(int *arr);

// Use pointer arithmetic to traverse an integer array
// and print all its elements.
int main(void) {
    int array[] = {10, 20, 30, 40, 50};
    int len = sizeof(array) / sizeof(array[0]);
    print_elements(&array);
}

// This doesn't make any sense at all
void print_elements(int *arr) {
    int arr_len = sizeof(&arr) / sizeof(&arr[0]);
    printf("Array elements using pointer arithmetic:\n");
    for (int i = 0, arr_len; i < arr_len; i++) {
        printf("Element %i: %i\n", i, *(arr + i));
    }
}
