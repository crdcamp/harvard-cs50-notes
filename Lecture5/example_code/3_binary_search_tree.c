#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *left;
    struct node *right;
} node;

bool recursive_search(node *tree, int number);
bool loop_search(node *tree, int number);

int main(void) {
    return 0;
}

bool recursive_search(node *tree, int number) {
    // Recursion base case
    if (tree == NULL) {
        return false;
    }
    else if (number < tree->number) {
        return recursive_search(tree->left, number);
    }
    else if (number > tree->number) {
        return recursive_search(tree->right, number);
    }
    // This should just be `else return true` but I'm leaving
    // it as is for clarity
    // (also a base case)
    else if (number == tree->number) {
        return true;
    }
}

// Here's the equivalent function written using for loops
bool loop_search(node *tree, int number) {
    while (tree != NULL) {
        if (number < tree-> number)
            tree = tree->left;
        else if (number > tree->number)
            tree = tree->right;
        else return true;
    }
    return false;
}
