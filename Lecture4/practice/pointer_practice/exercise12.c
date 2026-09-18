#include <stdio.h>

// Implement a function custom_strcpy that copies the content of a source string (src)
// to a destination string (dest) using only character pointers.
void custom_strcpy(const char *source, char *destination);

int main(void) {
    char source[] = "Pointer Mastery";
    char destination[50];

    custom_strcpy(source, destination);
    printf("%s", destination);
}

void custom_strcpy(const char *source, char *destination) {
    const char *p = source;
    int i = 0;

    while (*p != '\0') {
        *(destination + i) = *p;
        i++;
        p++;
    }
}
