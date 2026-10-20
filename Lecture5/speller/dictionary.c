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

node *insert_node(node *tree, char *word, int *left_size, int *right_size) {
    // If the tree is empty or you reach an empty node,
    if (tree == NULL) {
        new_node(word);
    }

    // If both sides of the tree are equal, send the word to the left
    if (left_size == right_size) return insert_node(tree->left, word, left_size++, right_size);
    // If the left side has less nodes than the right, send the word left
    else if (left_size < right_size) return insert_node(tree->left, word, left_size++, right_size);
    // If the right side has less nodes than the left, send the word right
    else if (left_size > right_size) return insert_node(tree->right, word, left_size, right_size++);

    return tree;
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
        node *tree_node = new_node(word);
        if (tree_node == NULL) {
            printf("Error allocating memory for node `new_tree`\n");
            return false;
        }

        // Now, how do we determine how to designate where the word goes?
        // Ideally, we want to evenly distribute the tree, yet the simple version
        // of this involves recounting the tree's left and right node count at each
        // iteration. This is evidently very inefficient, as you'd be traversing the
        // tree multiple times throughout the insertion

        // Actually, if you iterate through the tree instead of using recursion,
        // you might not have to worry about traversing the entire tree every time.
        // You can instead just traverse it once, and add to the left/right count
        // every time you add a word (this might be complicated by the binary structure though)
        // SO, let's try that
        int index = hash(word);
        static int *left_size = 0;
        static int *right_size = 0;

        // The first check need to determine if both counts are equal
        // If they are, let's just assign the word to the left
        // There's gotta be a bettet way to keep track of the left and right
        // size. `insert_node` could instead return a struct containing that data,
        // but that might make it impossible to actually insert the node
        insert_node(tree_node, word, left_size, right_size);

        // You might have to reset the left and right sizes for further
        // dictionary loads (a problem to diagnose later)
        // Or, you can just set them both to 0 in `unload`

    // Close the dictionary file and return `true`
    fclose(dictionary_file);
    return true;
    }
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
// Shouldn't this just be part of `load` if we don't want to iterate through
// the entire hash table again? that would be BLAZINGLY FAST wouldn't it?
unsigned int size(void) {
    printf("Function `size` not yet implemented\n");
    return 0;
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
