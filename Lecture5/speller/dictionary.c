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

    // Don't forget to experiment with flexible array members for `word`, although
    // you may run into some difficulties with implementing this
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
    printf("Loading '%s' into memory\n", dictionary);
    FILE *dictionary_file = fopen(dictionary, "r");
    if (dictionary_file == NULL) {
        printf("Error opening %s\n", dictionary);
        return false;
    }

    // Iterate through the dictionary and load it into memory (the hash table)
    char *word;
    char word_buffer[LENGTH + 2];
    size_t word_buffer_size = sizeof(word_buffer);
    size_t hash_node_size = sizeof(node);
    while ((word = fgets(word_buffer, word_buffer_size, dictionary_file)) != NULL) {
        // Strip `\n` from the end of `word` if found
        char last_char = word[strlen(word)-1];
        if (last_char == '\n') {
            word[strlen(word)-1] = 0;
        }
        // If there's no newline, send a warning
        else {
            printf("Warning: Newline character not found for word '%s'\n", word);
            continue;
        }

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
        // WE DON'T NEED TO WALK THE ENTIRE LINKED LIST HERE. JUST INSERT AT HEAD!
        else {
            while (current_node->next != NULL) {
                current_node = current_node->next;
            }
            current_node->next = hash_node;
        printf("Loaded '%s' into memory\n", hash_node->word);
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

    printf("Dictionary word count: %i\n", word_count);
    return word_count;
}

// This will need to be edited when you start adjusting the
// hash table a bit more
// Returns true if word is in dictionary, else false
bool check(const char *word) {
    // Convert to lowercase to ensure accuracy
    // (Also could be replaced with `strcasecmp`, but that was never introduced in the course)
    char word_lower[LENGTH + 1];
    int i = 0;
    while (word[i] != '\0') {
        word_lower[i] = tolower(word[i]);
        i++;
    }

    // Determine the table index by hashing the word
    int index = hash(word_lower);

    // Access the values of that index
    node *current_node = table[index];
    while (current_node != NULL) {
        // Compare `word` to the words in the linked list
        if (strcmp(current_node->word, word_lower) == 0) {
            return true;
        }
        // If no match, move on to the next node
        else current_node = current_node->next;
    }

    // If the word isn't found, return false
    return false;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void) {
    // TODO
    return false;
}
