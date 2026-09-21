#include <stdio.h>
#include <ctype.h>

unsigned int hash(const char *name);

int main(void) {

}
// Hashmap for looking up contacts
// We use `unsigned int` here since
unsigned int hash(const char *name) { // Use const to ensure the value isn't changed in memory
    // Convert to uppercase and subtract 65 ('A'). We do this to index the values at 0
    // This will return a number 0-25 inclusive
    return toupper(name[0] - 'A');
}
