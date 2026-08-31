# Links

* [Lecture video](https://cs50.harvard.edu/x/weeks/3/)
* [Lecture notes](https://cs50.harvard.edu/x/notes/3/)
* [Lecture VS Code](https://cs50.dev/)
* [Manual Pages](https://manual.cs50.io/)
* [Problem Set 3](https://cs50.harvard.edu/x/psets/3/)

# Algorithms

**Big O Notation:**

![Big O Notation Graph](images/O_of_n_graph.png)

# Linear Search

Let's say we have an array (that's suspiciously similar to the lockers in the lecture), like the following:

![Array Memory Example](images/array__memory_example.png)

* We can imagine that we have a problem where we want to know "Is the number `50` inside the array? A computer must look at each "locker" (index) to be able to see if the number `50` is inside. This is called *searching*.
* We can hand out array to an algorithm, wherein it will search through the lockers to see if the number `50` is behind one of the doors, returning the value `true` or `false`.

Here's some pseudocode to demonstrate this:

```pseudo
For each door from left to right
  If 50 is behind door
    Return true
Return false
```

This could be translated to the following (still not actual code, but closer):

```pseudo
For i from 0 to n-1
  If 50 is behind doors[i]
    Return true
Return false
```

# Binary Search

Another method to find `50`. Assuming that the values within the lockers have been arranged from smallest to largest, the pseudocode for binary search would be like this:

```pseudo
If no doors left
  Return false
If 50 is behind middle door
  Return true
Else if 50 < middle door
  Search left half
Else if 50 > middle door
  Search right hald
```

Same as before, we can narrow this down to:

```pseudo
If no doors left
  Return false
If 50 is behind doors[middle]
  Return true
Else if 50 < doors[middle]
  Search doors[0] through doors[middle -1]
Else if 50 > doors[middle]
  Search doors[middle + 1] through doors[n - 1]
```

Notice that were doing `[middle + 1]` and `[middle -1]`, since we've already searched the middle "locker".

# Running Time

Back to the Big O baby! Rather than being ultra-specific about the mathematical efficiency of an algorithm, computer scientists discuss efficiency in terms of *the order of* various running times. Here's the graph again for you:

![Big O Notation Graph](images/O_of_n_graph.png)

In the above graph, the first algorithm is *O*(*n*), or **the order of n**. The second one is *O*(*n*) as well, in that constraints are dropped in big O. The third is *O*(log *n*).

Some common running times we may see are:

![Running Times](images/o_n_common_running_times.png)

* Of the running times above, *O*(*n*^2) is considered the slowest running time. *O*(1) is the fastest.
* **Linear search** was of order *O*(*n*) because it would take *n* steps in the worst case to run.
* **Binary search** was of order *O*(log *n*) because it would take fewer and fewer steps to run, even in the worst case.

**We're interested in both the worst case, or *upper bound*, and the best case, or *lower bound*.**
* The <math mathvariant="normal">&#x3A9;</mi> symbol is used to denote the **best case** of an algorithm, such as <math mathvariant="normal">&#x3A9;</mi>(log *n*).
* The <mi mathvariant="normal">&#x398;</mi> symbold is used to denote **where the upper bound and lower bound are the same**: Where the best case and worst case running times are the same.
* **Asymptotic notation** is the measure of how well algorithms performs as the input gets larger.

# search.c

An example of linear search would be as follows:

```c
#include <cs50.h>
#include <stdio.h>

int main(void) {
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    // Search for number
    int n = get_int("Number: ");
    for (int i = 0; i < 7; i++) {
        if numbers[i] == n) {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```

Pretty self-explainable code here. No need to elaborate. But, what if we wanted to search for a string within an array?

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    // Search for string
    string s = get_string("String: ");
    for (int i = 0; i < 6; i++) {
        if (strcmp(strings[i], s) == 0) {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```

As covered in the lecture, `strcmp` will return `0` if the strings are the same. You can interpret differences in the strings that return values greater or less than `0`, but the lecture didn't elaborate too much on this.

Visit the [CS50 manual pages](https://manual.cs50.io/3/strcmp) for more info on `strcmp`.

# phonebook.c

We can combine these ideas of both numbers and strings into a single program:

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    string names[] = {"Kelly", "David", "John"};
    string numbers[] = {"+1-617-495-1000", "+1-617-495-1000", "+1-949-468-2750"};

    // Search for name
    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++) {
        if (strcmp(names[i], name) == 0) {
            printf("Found %s\n", numbers[i]);
        }
    }
    printf("Not found\n");
    return 1;
}
```

Again, pretty self-explainable code here. The index of both the name and number are assumed to be the same.

However, now we are *finally* being introduced to structs!

# Structs

Building off the previous example, it'd clearly be better to have the names more tightly associated with the numbers. So... stucts!

Here's how you define a struct:

```c
typedef struct {
    string name;
    string number;
} person;
```

Now let's implement this struct into the example:

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    string name;
    string number;
} person;

int main(void) {
    // Create an array of 3 structs
    person people[3];

    people[0].name = "Kelly";
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-617-495-1000";

    people[2].name = "John";
    people[2].number = "+1-949-468-2750";

    // Search for name
    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```

Since this confused you a lil, notice that we define the array with length `3`, when you'd assume that we'd define it as `2`, since you're used to zero indexing. Well... apparently zero indexing doesn't apply when creating arrays. In that instance, the number you see in the array definition is literal, but you still need to create structs from `0` to `2`. Strange, but that's the way it is.
