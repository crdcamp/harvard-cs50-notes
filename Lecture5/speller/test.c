#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *word = "meow\n";
    int word_len = strlen(word);

    printf("Before: %s", word);


    // Strip the '\n` character

    printf("After: %s\n", word);

    return 0;
}
