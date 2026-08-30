#include <stdio.h>

// The length of an array (the number of elements in it)
// can be found by dividing the array size by the size
// of an element in the array

// I'm pretty sure this wouldn't work with an array of
// strings, however

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};

    int arrSize = sizeof(arr); // Results in 20 bytes
    int elementSize = sizeof(arr[0]); // Bytes in single element
    int arrLen = arrSize / elementSize; // Length of array

    printf("Array size: %i\n", arrSize);
    printf("Element size: %i\n", elementSize);
    printf("Array length: %i\n", arrLen);
}
