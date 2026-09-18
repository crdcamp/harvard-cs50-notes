#include <stdio.h>

// Use a pointer to iterate through a string and print
// each character on a new line, stopping at the null terminator.
void print_each_line(char *message);

int main(void) {
     char *message = "C Pointers";
     print_each_line(message);
}

void print_each_line(char *message) {
    char *m_p = message;
    while (*m_p != '\0') {
        printf("%c\n", *m_p);
        m_p++; // Iterate to next pointer to get the next char
    }
}
