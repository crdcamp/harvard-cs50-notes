#include <stdio.h>

void print_array(int *array, int size, char *message);
void reverse_array(int array[], int size);

int main(void) {
    int numbers[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    print_array(numbers, size, "ORIGINAL: ");
    reverse_array(numbers, size);
    print_array(numbers, size, "REVERSED: ");

    return 0;
}

void print_array(int *array, int size, char *message) {
    printf("%s", message);
    for (int i = 0; i < size; i++) {
        printf("%i", array[i]);
    }
    printf("\n");
}

void reverse_array(int *array, int size) {
    for (int i = 0; i < size / 2; i++) {
        // Create temporary `int` value from the current index
        int tmp = array[i];
        // Assign last index int value to current index address
        *(array + i) = array[size - 1 - i]; // -1 cause ya gotta remember that `i` can be 0
        // Assign temp int value to the last index
        *(array + size - 1 - i) = tmp;
    }
}
