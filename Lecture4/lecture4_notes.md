# Links

* [Lecture Video]()
* [Lecture Notes](https://cs50.harvard.edu/x/notes/4/)
* [Pointer Practice](https://pynative.com/c-programming-pointers-exercises/)
* [Malloc Practice]()
* [CS50 Manual Pages](https://manual.cs50.io/)

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

## More on Pointers

[Source Video](https://www.youtube.com/watch?v=XISnO2YhnsY&time_continue=626&source_ve_path=MjE0Mjgz&embeds_widget_referrer=https%3A%2F%2Fcs50.harvard.edu%2F&embeds_referring_euri=https%3A%2F%2Fvideo.cs50.io%2F&embeds_referring_origin=https%3A%2F%2Fvideo.cs50.io)

* Keep in mind that memory (RAM) is essentially a giant array of byte-sized cells.
* Similar to how we can access individual elements of an array by indicating which index location we want, we can do the same with the **addresses** in memory.

There's only one critical thing to remember about pointers: **pointers are just addresses!**

* A pointer is a data item whose *value* is a memory address and *type* describes the data located at that memory address.
* As such, pointers allow data structures and/or variables to be shared among functions.
* Pointers make the *computer environment more like the real world*.

### Creating Pointers

The simplest pointer available to us in C is the `NULL` pointer,  which (obviously) points to nothing.

* When you create a pointer and you don't set its value immediately, you should **always** set the value of the pointer to `NULL`.
* You can check whether a pointer is `NULL` using the equality operator `==`.

Another easy way to create a pointer is to simply **extract** the address of an already existing variable. We can do this with the address extraction operator `&`

* If `x` is an `int`-type variable, then `&x` is a pointer-to`int` whose value is the address of `x`.
* If `arr` is an array of `double`s, then `&arr[i]` is a pointer-to-double whose value is the address of the `i`th element of `arr`.
* An array's name, then, is actually just **a pointer to its first element**, just like what we covered with strings. In summary, **an array's name is just a pointer**.

### The Purpose of Pointers

The main purpose of a pointer is to allow us to modify or inspect the location to which it points. We do this by **dereferencing** the pointer.

If we have a pointer-to-`char` called `pc`, then `*pc` is the data that lives at the memory address stored inside the variable `pc`.

**In summary:**
* `*` gives us the actual data we're pointing to. This is the **dereferencing** part. Thus, `*` is called the **dereference operator**.
* `&` gives us the address of the data in memory.
* `*` *goes to the reference* and accesses the data at that memory location, allowing you to manipulate it at will.

### Pointing to NULL

We mentioned earlier that if we create a pointer and don't use its value immediately we should always set the value of the pointer to `NULL`.

However, **if we try to dereference a pointer whose value is `NULL` it results in a segmentation fault**.

This is actually a good behavior, since it defends against accidental dangerous manipulation of unknown pointers. You'd rather have your program crash than manipulate data in an unintended manner.

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

Note that if the provide string is greater than 4 bytes you might get an error.

# Defining Our Own Data Types

* The C keyword `typedef` provides a way to create a shorthand or rewritten name for data types.
* The basic idea is to first define a type in the normal way, then alias it to something else.

Here's an example

```c
typedef unsigned char byte;
```

Now we can just use `byte` instead of `unsigned char`. Remember this example?

```c
typedef char * string
```

Since a string is simply a pointer to the first element in an array of `char`s, this "just works" ~ Todd Howard (thank you Todd Howard).

`typedef` becomes a bit more powerful when you start combining it with `struct`s. Structures have a two word type name, so they can be a bit annoying to work with. We can use `typedef` to streamline things a bit.

```c
struct car {
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
};
typedef struct car car_t;
```

You can also do it this way as well (which is clearly the recommended syntax for structs):

```c
typdef struct car {
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
} car_t;
```

Very nice. Very useful.

# File Pointers

* The ability to read data from and write data to files is the primary means of storing **persistent data**.
* The abstraction of files that C provides is implemented in a data structure known as `FILE`.
* Almost universally when working with files, we'll be using pointers to them, `FILE*`.

Generally, while *pointers* and *file pointers* might be related, they are ultimately two different things. So just keep that in mind.

The file manipulation functions all live in `stdio.h`. All of them accept `FILE*` as one of their parameters, except for the function `fopen()`, which is used to get a file pointer in the first place.

Some of the most common input/output functions that we'll be working on are:

```c
fopen() fclose()
fgetc() fputc()
fread() fwrite()
```

**`fopen()`**

* `fopen()` (obviously) opens a file and returns a pointer to it.
* You always want to check the return value to make sure you don't get back `NULL`.

```c
FILE* ptr = fopen(<filename>, <operation>);
```

You can use the `"r"`, `"w"`, or `"a"` operation when opening a file. You're already familiar with all these.

**`fclose()`**

Simply closes the file (duh).

```c
fclose(<file_pointer>);
```

**`fgetc()`**

* Reads and returns the next character from the file pointed to.
* Note: The operation of the file pointer passed in as a parameter must be `"r"` for read, or you will get an error.

```c
char ch = fgetc(<file_pointer>);
```

The ability to get single characters from files, if wrapped in a loop, means we could read all the characters from a file and print them to the screen, one-by-one, essentially:

```c
char ch;
while((ch = fgetc(ptr)) != EOF)
    printf("%c", ch);
```

We might put this in a file called `cat.c` after the Linux command `cat` which essentially does just this.
