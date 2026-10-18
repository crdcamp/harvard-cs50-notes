// Implements a dictionary's functionality
// You don't need to edit anything in this file
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

const unsigned int N = 26;

// Hash table
node *table[N];

// Hashes word to a number
unsigned int hash(const char *word) {
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Create a new node for the binary tree
node *new_node(char word[LENGTH + 1]) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        return NULL;
    }

    strcpy(new_node->word, word);
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// Loads dictionary into memory, returning true if successful, else false
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
    size_t tree_size = sizeof(node);
    while ((word = fgets(word_buffer, word_buffer_size, dictionary_file)) != NULL) {
        // Strip `\n` from the end of `word`
        int word_size = strlen(word);
        if ((word_size - 1) == '\n') {
            word[word_size - 1] = 0;
        }
        // If there's no newline, keep er goin
        else {
            continue;
        }

        // Create a new node for the binary tree
        node *tree = new_node(word);
        if (tree == NULL) {
            printf("Error allocating memory for node `new_tree`\n");
            return false;
        }

        // Now, how do we determine how to designate where the word goes?
        // We want the full tree to be
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
