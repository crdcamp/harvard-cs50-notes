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

// Now that we've created a balanced tree, it's time to start thinking
// about how we can convert this into a sorted tree

// To begin with, we obviously need to do this alphabetically, which by
// extension can most likely be done using the < and > symbols, as we know
// that chars are essentially just integers in disguise

// It's worth noting that this will  require iterating over the word,
// which will certainly affect load time, but this will also drastically
// increase the search time. This can also be alleviated with a better
// hash function in addition to more indices in the hash table,
// as more indices == less recursion when inserting words (ideally)

// Now, what tools do we have at our disposal?

// Well, the earlier note about iterating over the entire word is probably
// partially incorrect. We can just iterate until we've reached the the end
// of the shorter word. Moreover, I still need to fully picture how to actually
// alphabetically organize the words, since that's a bit of a challenge.

// Let's begin with a test file and see where to go from there.

node *insert_node(node *root, char *word, int word_len) {
    // If the tree is empty or you reach an empty node,
    if (root == NULL) {
        return new_node(word);
    }

    if (strcasecmp(root->word, word) < 0) {
        root->left = insert_node(root->left, word, word_len);
    }

    else if (strcasecmp(root->word, word) > 0) {
        root->right = insert_node(root->right, word, word_len);
    }

    return root;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary) {
    printf("Loading dictionary...\n");
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
        int word_len = strlen(word);
        if ((word[word_len - 1]) == '\n') {
            word[word_len - 1] = 0;
        }
        // If there's no newline, keep er goin
        // (there should be error handling here, but we're not worried about that here)
        else {
            continue;
        }

        // Insert the tree into the appropriate hash index
        int index = hash(word);
        table[index] = insert_node(table[index], word, word_len);
    }

    // If loop finished successfully, close the dictionary file and return `true`
    // for (int i = 0; i < N; i++) {
    //     print_tree(table[i], 4);
    // }
    printf("Dictionary loaded\n");
    fclose(dictionary_file);
    return true;
}

// Helper function for counting nodes
int size_helper(node *root) {
    if (root == NULL) {
        return 0;
    }

    return size_helper(root->left) + 1 + size_helper(root->right);
}

unsigned int size(void) {
    unsigned int size = 0;
    for (int i = 0; i < N; i++) {
        if (table[i] != NULL) {
            size += size_helper(table[i]);
        }
        else continue;
    }
    return size;
}

int check_helper(node *root, const char *word) {
    if (root == NULL) {
        return -1;
    }

    int check = strcasecmp(root->word, word);

    if (check < 0) {
        return check_helper(root->left, word);
    }
    if (check > 0) {
        return check_helper(root->right, word);
    }

    // If it's not greater or less than 0, then it's 0 dumbass
    return 0;
}

bool check(const char *word) {
    int index = hash(word);
    if (check_helper(table[index], word) == 0) {
        return true;
    }
    else return false;
}

void unload_helper(node *root) {
    if (root != NULL) {
        unload_helper(root->left);
        unload_helper(root->right);
        free(root);
    }

    return;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void) {
    for (int i = 0; i < N; i++) {
        if (table[i] != NULL) {
            unload_helper(table[i]);
        }
        else continue;
    }

    return true;
}
