#include <stdio.h>
// Hash tables are literally just key-value pairs
// It's essentially an evolution of a linked list combined with an array
// This following example keeps building on the contact list idea
typedef struct node {
    char *name;
    //char *number; We're not worried about numbers for this example
    struct node *next;
} node;

// Think about it: You have 26 letters in the alphabet
// You likely know multiple people whose name begins with
// the same letter. While each array index can only hold
// one value at a time, there's nothing preventing you from
// linking and sorting other values together that are anchored
// to a specific index. Like dude... fucking genius... and also super interesting
// To summarize: A hash table is an **array of linked lists**
node *table[26];
