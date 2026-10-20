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

    // Assign the word
    strcpy(new_node->word, word);

    // Assign the left and right nodes as NULL
    new_node->left = NULL;
    new_node->right = NULL;

    // Initiate the left and right sizes
    new_node->left_size = 0;
    new_node->right_size = 0;

    return new_node;
}

void print_tree(node *root, int level)
{
        if (root == NULL)
                return;
        for (int i = 0; i < level; i++)
                printf(i == level - 1 ? "|-" : "  ");
        printf("%s\n", root->word);
        print_tree(root->left, level + 1);
        print_tree(root->right, level + 1);
}

node *insert_node(node *root, char *word) {
    // If the tree is empty or you reach an empty node,
    if (root == NULL) {
        return new_node(word);
    }

    // If both sides of the tree are equal, send the word to the left
    if (root->left_size == root->right_size) {
        root->left_size++;
        return insert_node(root->left, word);
    }
    // Otherwise, if the left side has less nodes than the right, send the word left
    else if (root->left_size < root->right_size) {
        root->left_size++;
        return insert_node(root->left, word);
    }
    // Otherwise, if the right side has less nodes than the left, send the word right
    else if (root->left_size > root->right_size) {
        root->right_size++;
        return insert_node(root->right, word);
    }

    print_tree(root, 4);

    return root;
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
    node *root = NULL;
    while ((word = fgets(word_buffer, word_buffer_size, dictionary_file)) != NULL) {
        // Strip `\n` from the end of `word`
        int word_size = strlen(word);
        if ((word[word_size - 1]) == '\n') {
            word[word_size - 1] = 0;
        }
        // If there's no newline, keep er goin
        else {
            continue;
        }

        // Insert the node into the binary tree while updating left and right
        // tree size
        root = insert_node(root, word);
        if (root == NULL) {
            printf("Error allocating memory for `root`\n");
            return false;
        }

        // Insert the tree into the appropriate hash index
        int index = hash(root->word);
        table[index] = root;

        printf("RESULTING TREE FOR INDEX %i\n", index);
        print_tree(root, 4);
    }

    // If loop finished successfully, close the dictionary file and return `true`
    fclose(dictionary_file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
// Shouldn't this just be part of `load` if we don't want to iterate through
// the entire hash table again? that would be BLAZINGLY FAST wouldn't it?
unsigned int size(void) {
    return 0;
}

// This will need to be edited when you start adjusting the
// hash table a bit more
// Returns true if word is in dictionary, else false
bool check(const char *word) {
    return false;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void) {
    return false;
}
