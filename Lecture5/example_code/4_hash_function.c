#include <ctype.h>
// Hashing is the function or routine used to assign the key values to the each entity in the database.
// Using hashing, We can easily access or search the values from database.
// Hashing is achieved by using Hash Table data structure.

unsigned int hash(const char *name);

int main(void) {

}
// Hashmap for looking up contacts
// We use `unsigned int` here to ensure we're not converting any letters to a negative index
// Use const to ensure the value isn't changed in memory. In fact, think of `const` more like this,
// rather than just a "constant" variable
unsigned int hash(const char *name) {
    // Convert to uppercase and subtract 65 ('A'). We do this to index the values
    // This will return a number 0-25 inclusive
    return toupper(name[0] - 'A');
}
