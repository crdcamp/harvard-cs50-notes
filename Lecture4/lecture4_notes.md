# Memory

# Hexadecimal

You main question was "why... why use this?" The most basic explanation is essentially that hexadecimal is a good way to write condensed binary values. It's pretty much just more information condensed into less characters. This is why we write things like colors and memory addresses in hexadecimal rather binary, as there would just be way too many digits to represent them in something other than hexadecimal.

Hexadecimal is a system of counting that has 16 counting values. They are as follows:

```0 1 2 3 4 5 6 7 8 9 A B C D E F```

* Hexadecimal is also known as *base-16*.
* When counting in hexadecimal, each column is a power of 16.
* 255 is the highest number you can count using a two-digit hexadecimal system.
* By convention, hexadecimal numbers are often represented with the `0x` prefix.

# Pointers

Consider the following code:

```c
#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%p\n", &n);
}
```

`%p` allows us the view the address of a location in memory. `&n` can be literally translated as "the address of `n`".

A **pointer** is a variable that stores the address of something. It's an address in your computer's memory.

Consider the following code:

```c
int n = 50;
int *p = &n;
```

*`p` is a pointer that contains the address of an integer `n`. If we modify the code like this:

```c
#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
}
```

This has the same effect as the previous code. `p` simply points to the address of `n`.

Here's how you spiffed up the code a bit to further confirm how all this works:

```c
#include <stdio.h>

int main(void) {
	int n = 50;
	int *p = &n;

	printf("Address of p: %p\n", p);
	printf("Value of p: %i\n", *p);

	printf("\n");

	printf("Address of n: %p\n", &n);
	printf("Value of n: %i\n", n);
}
```

# Strings

Now that we understand a bit about pointers, we can start thinking about how a `string` actually works in C.

Recall that a string is simply an array of characters. For instance, consider a string such as `HI!` assigned to a variable `s`:

```c
int main(void) {
    char *s = "HI!";
}
```

This can be represented as:

```H I ! \0```

However, what is `s` really? Where is the `s` stored in memory? Well... this also kinda taps into why we store strings using pointers. A string's location in memory is defined by its first element, and concluded with the escape character `\0`.

Therefore, a strings pointer (again) always points to the strings first element's memory location, while the rest of the strings follow this initial memory placement iteratively.

You can confirm this with the following code:

```c
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}
```

# Pointer Arithmetic

Pointer arithmetic is the ability to do math on locations of memory. You can modify the above code to print out each memory location in the string as follows:

```c
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
}
```

Pretty simple stuff (that could probably lead into some extremely complex applications).

# String Comparison

Main takeaway: trying to compare strings using the `==` operator results in the memory locations of the strings being compared, not the strings themselves. This is why we always use `strcmp` when comparing strings.

# Copying and malloc

Consider the following code:

```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get a string
    string s = get_string("s: ");

    // Copy string's address
    string t = s;

    // Capitalize first letter in string
    t[0] = toupper(t[0]);

    // Print string twice
    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
```

When we say `string t = s`, we're copying the address of `s` to `t`, not the actual string (a similar issue as before).

To be able to actually copy a string, we need `malloc` (memory allocation) from the `stdlib` library. this funciton allows you to allocate a block of a specific size of memory. Second, `free` allows you to tell the compiler to free up that block of memory when you're done with it.

We can use `malloc` to copy a string like this:

```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Get a string
    char *s = get_string("s: ");

    // Allocate memory for another string
    char *t = malloc(strlen(s) + 1);

    // Copy string into memory, including '\0'
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    // Capitalize copy
    t[0] = toupper(t[0]);

    // Print strings
    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
```

Notice that `malloc(strlen(s) + 1)` creates a block of memory that's the length of the string `s` plus one to account for the nul `\0` character. We also use `<=` for the same reason when iterating through string `s` to copy it.

This was just a demonstration. Of course, C has a built in function for this called `strcpy`, yet you'd still need to use `malloc`:

```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *s = get_string("s: ");
    char *t = malloc(strlen(s) + 1);

    // Note we start with `t` then use `s`
    // (for some reason the creator of C decided to make this counterintuitive)
    strcpy(t, s);
    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
```

Both `get_string` and `malloc` return `NULL`, a **special value in memory**, in the event something goes wrong. This can be used for error handling like so:

```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Get a string
    char *s = get_string("s: ");
    if (s == NULL)
    {
        return 1;
    }

    // Allocate memory for another string
    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
    }

    // Copy string into memory
    strcpy(t, s);

    // Capitalize copy
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    // Print strings
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // Free memory
    free(t);
    return 0;
}
```

# Garbage Values

When you ask the compiler for a block of memory, **there's no guarantee that this memory will be empty**.

It's very possible (and pretty much guaranteed) that the memory you allocated was previously utilized by the computer. Accordingly, you may see *junk* or *garbage values*. This is a result of you getting a block of memory but not initializing it. For example:

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int scores[1024];
    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }
}
```

Since you initialized `int scores[1024];` without actually assigning any data to it, you're just gonna get a bunch of random values from previous operations.


# Swapping

A common need in programming is to swap values. To do so, this requires a temporary holding space:

```c
#include <stdio.h>

void swap(int a, int b);

int main(void) {
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int a, int b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
```

Notice the pretty blatant use of pointers here. We need them because of the scope of the `swap` function. Without the pointers, you're just passing copies of `x` and `y` to `swap`, not the actual values themselves.

Pointers take care of this by *pointing* to the actual memory you want to edit. Otherwise (again) you're just working with copies of variables.

# Overflow

* A **heap overflow** is when you overflow the heap, touching areas of memory that the program you've created isn't supposed to.
* A **stack overflow** is when too many functions are called, overflowing the amount of memory available.
* Both of these are condidered **buffer overflows**.

# scanf

This literally just repolaces all the "get" fucntions that the CS50 library has provided so far.

`scanf` just accepts user input. Pretty simple! Here's an example:

```c
#include <stdio.h>

int main(void) {
    int n;
    printf("n: ");
    scanf("%i", &n);
    printf("n: %i\n", n);
}
```

However, attempting to reimplement `get_string` isn't that simple, as strings can be any length of bytes:

```c
#include <stdio.h>

int main(void) {
    char s[4];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}
```

Notice that no `&` is required because **array names in C act as pointers**. Still, we haven't allocated memory for `s`:

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(4);
    if (s == NULL)
    {
        return 1;
    }
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
    free(s);
    return 0;
}
```

Note tha if the provide string is greater than 4 bytes you might get an error.
