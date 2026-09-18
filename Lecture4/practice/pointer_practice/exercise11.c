#include <stdio.h>

// Write a function custom_strlen to calculate the length of a string (null-terminated character array)
// without using the standard C library function strlen(). The function must use a character pointer to
// traverse the string until it finds the null terminator (\0).

int custom_strlen(char *string);

int main(void) {
    char *string_input = "Hello Pointers!";
    int string_len = custom_strlen(string_input);
    printf("Length: %i\n", string_len);

    return 0;
}

int custom_strlen(char *string) {
    const char *p = string;
    int length = 0;

    while (*p != '\0') {
        p++; // Move to the next `char` in the pointer
        length++;
    }

    return length;
}
