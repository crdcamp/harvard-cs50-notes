#include <stdio.h>

void sum_array(int *arr, int length);

// Write a function sum_array that accepts an integer pointer
// (the array base address) and the size of the array. The function
// must calculate and return the sum of all elements using pointer
//  arithmetic for traversal.
int main(void) {
    int numbers[] = {10, 5, 8, 2, 15};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    sum_array(numbers, length);

    return 0;
}

void sum_array(int *arr, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += *(arr + i);
    }

    printf("The sum of array elements is: %i\n", sum);
}
