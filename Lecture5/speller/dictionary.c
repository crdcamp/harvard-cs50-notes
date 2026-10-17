// Implements a dictionary's functionality
// You don't need to edit anything in this file
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// The dictionary is simply a hash table. Since there's a lot of words out there,
// this is clearly a great way to store and find them with relative ease and speed
// This also clearly means you'll want to work on `dictionary.c` before `speller.c`

// Represents a node in a hash table
typedef struct node
{
    // Could probably edit this later to dynamically allocate the
    // size of the word rather than having a hard set value (double check the assignment rules for this)
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
bool check(const char *word) {
    // TODO
    return false;
}

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
// For now, try to just get it working
bool load(const char *dictionary) {
    // Open the dictionary file
    printf("Loading '%s' into memory\n", dictionary);
    FILE *dictionary_file = fopen(dictionary, "r");
    if (dictionary_file == NULL) {
        printf("Error opening %s\n", dictionary);
        return false;
    }

    // Iterate through the dictionary and load it into memory (the hash table)
    char *word;
    char word_buffer[LENGTH + 1];
    size_t word_buffer_size = sizeof(word_buffer);
    size_t hash_node_size = sizeof(node);
    while ((word = fgets(word_buffer, word_buffer_size, dictionary_file)) != NULL) {
        // Strip `\n` from the end of `word`
        word[strlen(word)-1] = 0; // 0 is the NULL terminator in ASCII

        // Allocate memory for the `hash_node` struct
        node *hash_node = malloc(hash_node_size);
        if (hash_node == NULL) {
            printf("Error allocating memory for `hash_node`\n");
            return false;
        }

        // Convert the word to a hash index
        unsigned int hash_index = hash(word);

        // Initialize `hash_node`'s fields
        strcpy(hash_node->word, word);
        hash_node->next = NULL;

        // Check if the hash index is empty. If it is, insert `hash_node`
        node *current_node = table[hash_index]; // You're copying the address here, not the actual data
        if (table[hash_index] == NULL) {
            table[hash_index] = hash_node;
            printf("Loaded '%s' into memory\n", hash_node->word);
        }
        // Otherwise, iterate through a copy of the linked list until you reach `next == NULL`
        // Always remember that you need to make a COPY of the linked list and
        // traverse the COPY. Otherwise, you're just editing and breaking the original
        else {
            while (current_node->next != NULL) {
                current_node = current_node->next;
            }
            current_node->next = hash_node;
        printf("Loaded word '%s' into memory\n", hash_node->word);
        }
    }
        // Once you've found the last entry in the linked list, assign the new node to `next`

    // Close the dictionary file and return `true`
    fclose(dictionary_file);
    printf("'%s' successfully loaded into memory\n", dictionary);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
// Shouldn't this just be part of `load` if we don't want to iterate through
// the entire hash table again? that would be BLAZINGLY FAST wouldn't it?
unsigned int size(void) {
    // Check if the dictionary is loaded into memory
    size_t table_size = sizeof(table) / sizeof(table[0]);
    unsigned int null_count = 0;
    for (int i = 0; i < table_size;i++) {
        if (table[i] == NULL) {
            null_count++;
        }
    }
    if (table_size == null_count) {
        printf("Dictionary is empty or not loaded\n");
        return 0;
    }

    // This is probably gonna be a traversal of the array (outer loop),
    // followed by a traversal of the linked list (inner loop)
    unsigned int word_count = 0;
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void) {
    // TODO
    return false;
}
