// Declares a dictionary's functionality

// `#ifndef` is a conditional compilation of parts of the source file.
// It is essentially equivalent to `#if !defined`: https://devdocs.io/c/preprocessor/conditional
// This is optionally followed by any number of `#elif`, `elifdef`, or
// `elifndef` directives, then optionally includes at most one `#else`

// So, it essentially just says "if `DICTIONARY_H` is not defined, define it"
// This could be either some form of safer programming or some way to ensure
// that changes that happen during runtime don't carry over to here... or
// something else entirely. This will probably become clearer later

// Explanation from the lecture:
// These lines ensure that, even though `dictionary.c` and `speller.c` `#include`
// this file, `clang` will only compile it once. This makes the above explanations
// make a lot more sense as well. It's essentially to help performance. It prevents
// double declarations of macros when a header file is included in multiple files
// across a single project
// Very useful knowledge indeed yes mmmmmmm
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Represents a node in a hash table
typedef struct node
{
    // Don't forget to experiment with flexible array members for `word`, although
    // you may run into some difficulties with implementing this
    char word[LENGTH + 1];
    struct node *left;
    struct node *right;
} node;

typedef struct index_metadata {
    unsigned int index;
    int left_size;
    int right_size;
} index_metadata;

// Prototypes
// All these functions are found in `dictionary.c`
// These prototypes were left here so that they can
// be accessed fro0m `speller.c` and `dictionary.c`
unsigned int hash(const char *word);
node *new_node(char word[LENGTH + 1]);
node *insert_node(node *tree, char *word, int left_size, int right_size);
bool load(const char *dictionary);
unsigned int size(void);
bool check(const char *word);
bool unload(void);

#endif // DICTIONARY_H
