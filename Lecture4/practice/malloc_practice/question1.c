#include <stdlib.h>

struct ABC {
        int **ip;
}*sp;

// Store a value in memory provided by `sp`
int main(void) {
    // Allocate relevant memory size
    sp = malloc(sizeof(struct ABC));
}
