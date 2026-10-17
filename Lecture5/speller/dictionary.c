// Implements a dictionary's functionality
// You don't need to edit anything in this file
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// The dictionary is simply a hash table. Since there's a lot of words out there,
// this is clearly a great way to store and find them with relative ease and speed
// This also clearly means you'll want to work on `dictionary.c` before `speller.c`

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1]; // Always remember `+ 1` is for the NULL character `\0`
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
// 26 letters in the alphabet, so we want 26 indices to choose
// from in the hash table
// However, they note that you may want to increase this value
// depending on your own implementation. I suppose that depends on
// how many dictionary entries we're working with

// Also, if it's not too great of a challenge, maybe look into a
// tree structure to replace the linked lists in the hash table
// ... could be a lot faster if done correctly
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
// THIS IS A VERY VERY SLOW WAY TO DO THIS, BUT IT'S A START!
// Think... there's gotta be a way to do this without looping through
// the entire dictionary twice......

// `mmap` might be your answer here for a BLAZINGLY FAST load time
// For now, try to just get it working
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *dictionary_file = fopen(dictionary, "r");
    if (dictionary_file == NULL) {
        printf("Error opening %s\n", dictionary);
        return false;
    }

    char ch; // For determining the end of the file
    char *word; // For grabbing the actual word
    char word_buffer[LENGTH];
    size_t word_buffer_size = sizeof(word_buffer);

    // Loop through each character until you reach the end of the file
    // (But what if we can only use `fgets` instead? `ch` might be unnecessary here)
    // However, this might not be possible since `fgets` can only return NULL and not EOF
    while ((ch = fgetc(dictionary_file)) != EOF) {
        // Read each word in the file
        word = fgets(word_buffer, word_buffer_size, dictionary_file); // `fgets` reads an entire line, including whitespace, until a newline, EOF, or size limit is reached
        if (word == NULL) {
            printf("Error using `fgets` when loading dictionary `%s`\n", dictionary);
            return false;
        }

        // Add the word to the hash table
        unsigned int hash_index = hash(word);

        // Enter the word into the `node` struct

        // Put the struct in the corresponding `hash` index
    }

    // Close the dictionary file
    fclose(dictionary_file);

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
