#include <stdio.h>
#include <ctype.h>

#define VOWELS "aeiou"

// Count the number of vowels (A, E, I, O, U, and their lowercase counterparts)
// in a given string using a character pointer for traversal.
// (their solution to this one seems kinda retarded to me)
int count_vowels(char *string);

int main(void) {
    char sentence[] = "The quick brown fox Jumps over the lazy dog";
    int vowel_count = count_vowels(sentence);

    return 0;
}

int count_vowels(const char *s) {
    int count = 0;
    const char *p = s;

    while (*p != '\0') {
        char c = *p;

        // Check if the current character is a vowel (case-insensitive)
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
        p++; // Move to the next character
    }
    return count;
}
