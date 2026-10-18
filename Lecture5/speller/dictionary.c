// Implements a dictionary's functionality
// You don't need to edit anything in this file
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// The dictionary is simply a hash table. Since there's a lot of words out there,
// this is clearly a great way to store and find them with relative ease and speed
// This also clearly means you'll want to work on `dictionary.c` before `speller.c`

// Represents a node in a hash table
typedef struct node
{
    // Could probably edit this later to dynamically allocate the
    // size of the word rather than having a hard set value (double check the assignment rules for this)

    // Don't forget to experiment with flexible array members for `word`, although
    // you may run into some difficulties with implementing this
    char word[LENGTH + 1]; // Always remember `+ 1` is for the NULL character `\0`
    struct node *left;
    struct node *right;
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

// Hashes word to a number
unsigned int hash(const char *word) {
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
// THIS IS A VERY VERY SLOW WAY TO DO THIS, BUT IT'S A START!
// Think... there's gotta be a way to do this without looping through
// the entire dictionary twice......

// `mmap` might be your answer here for a BLAZINGLY FAST load time
// As an easier requirement USE HEAD INSERTION INSTEAD OF TAIL INSERTION
// For now, try to just get it working
bool load(const char *dictionary) {
    // Open the dictionary file
    FILE *dictionary_file = fopen(dictionary, "r");
    if (dictionary_file == NULL) {
        return false;
    }

    // Iterate through the dictionary and load it into memory (the hash table)
    char *word;
    char word_buffer[LENGTH + 2]; // `+ 2` instead of `+ 1` to account for `\n` char
    size_t word_buffer_size = sizeof(word_buffer);
    size_t root_size = sizeof(node);
    while ((word = fgets(word_buffer, word_buffer_size, dictionary_file)) != NULL) {
        // Strip `\n` from the end of `word`
        char last_char = word[strlen(word)-1];
        if (last_char == '\n') {
            word[strlen(word)-1] = 0;
        }
        // If there's no newline, keep er goin
        // There's potential here to corrupt the entire tree, but we're
        // only dealing with clean data here so it doesn't really matter
        else {
            continue;
        }

        // Allocate memory for the `root` struct
        node *root = malloc(root_size);
        if (root == NULL) {
            return false;
        }


    }
        // Once you've found the last entry in the linked list, assign the new node to `next`

    // Close the dictionary file and return `true`
    fclose(dictionary_file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
// Shouldn't this just be part of `load` if we don't want to iterate through
// the entire hash table again? that would be BLAZINGLY FAST wouldn't it?
unsigned int size(void) {
    // Traverse the `table` array and the linked lists in each index of the `table` array
    // you could
    unsigned int word_count = 0;
    for (int i = 0; i < N; i++) {
        node *current_node = table[i];
        if (table[i] == NULL) {
            continue;
        }
        while (current_node != NULL) {
            word_count++;
            current_node = current_node->next;
        }
    }

    return word_count;
}

// This will need to be edited when you start adjusting the
// hash table a bit more
// Returns true if word is in dictionary, else false
bool check(const char *word) {
    printf("Function `check` not yet implemented\n");
    return false;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void) {
    printf("Function `unload` not yet implemented\n");
    return false;
}
