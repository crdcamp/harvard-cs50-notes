#include <stdio.h>
#include <stdlib.h>

// `unsigned` is essentially saying "This sequence of 8 bits cannot be treated as a negative number"
// Remember that "unsigned" literally refers to negative/positive signs (dumbass)
typedef unsigned char BYTE;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Invalid entry: Must provide a source and destination file\n");
        return 1;
    }

    // Define source and destination files
    FILE *src = fopen(argv[1], "rb");
    FILE *dst = fopen(argv[2], "wb");

    // Copy file byte by byte
    BYTE b;

    // While you read one byte at a time...
    while (fread(&b, sizeof(b), 1, src) != 0) {
        // ... write that byte to the file
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(dst);
    fclose(src);
}
