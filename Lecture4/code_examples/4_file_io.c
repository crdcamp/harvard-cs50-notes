#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int open_and_write_file(char *filename, char *name, char *number);
int open_and_append_to_file(char *filename, char *name, char *number);

int main(void) {
    open_and_write_file("phonebook.csv", "Mr. Meow", "123-456-7890");
    open_and_append_to_file("phonebook.csv", "Mr. Miyagi", "610-723-5555");

    return 0;
}

// "w" will completely wipe the file
int open_and_write_file(char *filename, char *name, char *number) {
    // Open a file (whether it exists or not)
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return 1;
    }

    // Save `name` and `number` to the file's contents in csv format
    fprintf(file, "%s,%s\n", name, number);
    fclose(file);

    return 0;
}

// "a" will append to the file
int open_and_append_to_file(char *filename, char *name, char *number) {
    // Same as above only we're appending
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        return 1;
    }
    fprintf(file, "%s, %s\n", name, number);
    fclose(file);

    return 0;
}
