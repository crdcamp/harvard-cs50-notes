#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_int(void);
void get_string(void);

int main(void) {
    //get_int();
    get_string();

    return 0;
}

void get_int(void) {
    int n;
    printf("n: ");
    scanf("%i", &n);
    printf("n: %i\n", n);
}

// Things get trickier with string inputs since strings aren't a designated size,
// unlike ints which are always 4 bytes
void get_string(void) {
    char *s = malloc(strlen(s + 1)); // This is probably really bad practice and something I decided to do myself
    printf("s: ");
    // No `&` before the variable this time since `s` is already assigned as an address
    // If you were to set a pointer here, you'd be doing a pointer to a pointer... which sounds exhausting
    scanf("%s", s);
    printf("s: %s\n", s);
}
