// Simulate genetic inheritance of blood type
// Blood type combinations: OO, OA, OB, AO, AA, AB, BO, BA, BB
#define _DEFAULT_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
// This is a setup for a tree structure. More specifically, think of it
// as a "family tree"
// Since generations are (for our purposes) continuous in their definitions,
// we need to link the structs of one person to other people
// So, `struct person *parents[2];` gives us the opportunity to allocate
// memory for additional generations and limits us to filling that data
// strictly with a `person` struct
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

const int GENERATIONS = 3; // We don't want an infinite tree here, so we have to limit it
const int INDENT_LENGTH = 4; // Simply for print purposes

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srandom(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);
    if (p == NULL) {
        return 1;
    }

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    // Think of this step as a "skeleton" for the family tree
    // You're not filling in values yet, just defining the structure
    // of the tree
    person *new_person = malloc(sizeof(person));
    if (new_person == NULL) {
        printf("Error allocating memory for `new_person`\n");
        return NULL;
    }

    if (generations > 1)
    {
        // Note the use of recursion here. How does this work?
        // Well, the most obvious thing is that we're subtracting 1 in order to
        // eventually reach the base case of 1 defined in the beginning of
        // this function
        // Moreover, this simply allocates memory for each generation (the TODO that you
        // need to personally implement)
        // We may have allocated memory here, but we haven't linked anything just yet
        // KEEP IN MIND that the recursion will keep going from these 2 lines back to
        // the malloc until `generations` is not greater than 1. So, you've set up the
        // tree before
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // TODO: Set parent pointers for current person
        // With this requirement, the recursion makes even more sense
        // You're creating generations (logically) from the oldest to
        // the newest.
        // NOW we've linked this current generation of the family tree together
        new_person->parents[0] = parent0;
        new_person->parents[1] = parent1;

        // TODO: Randomly assign current person's alleles based on the alleles of their parents
        new_person->alleles[0] = parent0->alleles[random() % 2];
        new_person->alleles[1] = parent1->alleles[random() % 2];
    }

    // If there are no generations left to create
    else
    {
        // TODO: Set parent pointers to NULL
        new_person->parents[0] = NULL;
        new_person->parents[1] = NULL;

        // TODO: Randomly assign alleles
        new_person->alleles[0] = random_allele();
        new_person->alleles[1] = random_allele();
    }

    // TODO: Return newly created person
    return new_person;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // TODO: Handle base case
    if (p == NULL) return;

    // TODO: Free parents recursively
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // TODO: Free child
    free(p);
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Print parents of current generation
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = random() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
