# Links

* [Lecture video](https://www.youtube.com/watch?v=h5Gc1n8ZuU8)
* [Lecture notes](https://cs50.harvard.edu/x/notes/2/)
* [Manual Pages](https://manual.cs50.io/)
* [Problem Set 2]()

# Arrays

Preprocessing. Compiling. Assembling. Linking. Debugging. Arrays. Strings. Command-Line Arguments. Cryptography.

# Cryptography

The class begins with this encrypted message:

`U I J T  JT D T 5 0`

Which we're gonna find out decrypts to "This is CS 50".

# Debugging

This term was popularized by Dr. Grace Hopper, one of the OG dudes who worked on one of the first computers, the Harvard Mark I. As you know, the term "bug" comes from a literal bug being on one of the pages fed to the machine.

We're gonna start with this program as an example:

```c
int main(void) {
    printf("hello, world")
}
```

**What's already wrong**:
* Didn't use `#include <stdio.h>` to include the header file.
* Missing a semicolon at the end of `printf()`.
* `printf()` is missing a newline character.

The fixed code:

```c
#include <stdio.h>

int main(void) {
    printf("hello, world\n");
}
```

Note that the first two issues wouldn't let the program compile. However, the code would compile without the newline character, yet still be considered to have a bug.

This is the difference between a **syntax error** (won't compile at all) and a **logical error** (code doesn't behave as intended).

Now let's add some more to the code:

```c
#include <stdio.h>

int main(void) {
    name = get_string("What's your name? ");
    printf("hello, world\n");
}
```

Now, however, we're getting a new error:

```bash
error: use of underclared identifier `name`
```

This is because `name`'s type was never declared (you're already very familiar with this issue after the first assignment).

So, let's declare the variable type:

```c
#include <stdio.h>

int main(void) {
    string name = get_string("What's your name? ");
    printf("hello, world\n");
}
```

Results in:

```bash
error: use of undeclared identifier `string`; did you mean `stdin`?
```

As it turns out, `string` is part of the `cs50.h` header/library. This error is a bit misleading, as the compiler is just looking for the most similar word.

Let's fix that:

```c
#include <cs50.h>
#include <stdio.h>

int main(void) {
    string name = get_string("What's your name? ");
    printf("hello, world\n");
}
```

We're gonna ignore what a string *really* is for the next week or two (my guess is it's an array of `char`s). Just keep in mind that C has no native string type. What we call a "string" is just a convention: a contiguous block of `char`s in memory, where the end is marked by a `\0` (null) byte.

Now let's fix the logic for the introduction:

```c
#include <cs50.h>
#include <stdio.h>

int main(void) {
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}
```

# Defining Logical Errors in Your Code

When you want to define a logical problem in your code, and find out what's going wrong, `printf()` is your friend. Again, things your aware of, but maybe this will lead into a concept you aren't familiar with. Anyway, let's demonstrate this with an example where we do the whole Mario print three bricks thing:

```c
#include <stdio.h>

int main(void) {
    for (int i = 0 ; i <= 3; i++) {
        printf("#\n");
    }
}
```

There's a pretty blatant and deliberate mistake here: the `<=` operator should be `<`.

However, let's take a look at how we'd debug this with `printf()`:

```c
#include <stdio.h>

int main(void) {
    for (int i = 0 ; i <= 3; i++) {
        printf("i is %i\n", i);
        printf("#\n");
    }
}
```

Obviously results in:

```bash
i is 0
#
i is 1
#
i is 2
#
i is 3
#
```

As you already stated, the solution is as follow:

```c
#include <cs50.h>
#include <stdio.h>

int main(void) {
    for (int i = 0; i < 3; i++) {
        printf("#\n");
    }
}
```

Now let's work on making a better variant by **modularizing** it:

```c
#include <cs50.h>
#include <stdio.h>

void print_column(int height); // Function "prototype"

int main(void) {
    int h = get_int("Height: ");
    print_column(h);
}

void print_column(int height) {
    for (int i = 0; i < height; i++) {
        printf("#\n");
    }
}
```

As your code increases in complexity (and as you're already aware), `printf()` is not going to be sufficient enough to debug. Luckily, the course provides `debug50`. This automates the process of starting the debugger. Other than that, it's the equivalent to an actual debugger you'd use.

# debug50

`debug50` enables you to slow down and debug your code line-by-line. Let's use the previous example to help us understand why we were getting four instead of three `#`s. Here's the incorrect code again:

```c
#include <cs50.h>
#include <stdio.h>

void print_column(int height); // Function "prototype"

int main(void) {
    int h = get_int("Height: ");
    print_column(h);
}

void print_column(int height) {
    for (int i = 0; i <= height; i++) { // Reinstated "less than or equal to" error
        printf("#\n");
    }
}
```

In your terminal:

```bash
debug50 ./buggy
```

The result:

```bash
Looks like you haven't set any breakpoints. Set at least one breakpoint by clicking to the left of a
Line number and then re-run debua50!*
```

If you hover over the left side where the line numbers are, you'll notice these red dots appearing. This is where you can click on them and insert a break point. Now if you rerun the above command you can investigate everything in the debugger panel. In the panel, you'll see `h = 32764`, which is a **garbage value**, which is a default value inside of a variable that's a result of that memory being used for something else. The moment the code executes, that value will change (this is apparently a bit of an oversimplification).

There's also a "call stack" which shows what has been called.

I would add more to this, but this seems like something you'll have to learn through practice.

# Compiling - What's Really Happening

To begin with, `make` is not technically the compiler itself. The compiler you've been using is actually called `clang`, for "C language". What `make` is really doing is running:

```bash
clang hello.c
./a.out
```

`./a.out` is for **assembler output**. So, if you were to use the `clang` command and then use `ls`, you'd notice that there's a new file called `a.out` (the default name for the `clang` output).

Let's say you were going to try and run `clang hello.c` on this version of `hello.c`:

```c
#include <cs50.h>
#include <stdio.h>

int main(void) {
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}
```

Your output after running `clang hello.c` would result in this error:

```bash
/usr/bin/ld: /tmp/hello-b6391a.o: in function 'main': hello.c: (.text+0x16): undefined reference to 'get_string' clang: error: linker command failed with exit code 1
```

This is because you're just assuming that `clang` knows where to find the CS50 version of `get_string()`, and this clearly isn't the case. Technically, if you want the compiler to compile this code, you'd need to do the following:

```bash
clang hello.c -lcs50
```

`lcs50` "links" the cs50 library so that it knows what 0s and 1s belong to the `get_string()` function.

We can also change the output name from `a.out` to something else. We can use the following command line argument:

```bash
clang -o hello hello.c -lcs50
```

In the documentation for `clang`, it's stated that `-o` followed by any name/word of your choice renames the file (without having to resort to something like `mv`).

# Compiling - A Deeper Dive

Using the `-l` command to link the library certainly implies that something more interesting is going on that `make` is abstracting away. So, let's take a look at the actual code we're compiling.

**Compiling code refers to four different processes:**
1) Preprocessing
1) Compiling
1) Assembling
1) Linking

## Preprocessing

Consider this program:

```c
#include ‹stdio.h›

void meow(void);

int main(void) {
    for (int i = 0; i < 3; i++) {
        meow()
    }
}

void meow(void) {
    printf("meow\n")
}
```

A reminder that the prototype `void meow(void);` is necessary because we need to tell the compiler that `meow()` exists before using it (since the C compiler reads code from top to bottom). This is essentially what the headers do as well. For instance, the prototype for `printf()` is in `stdio.h`.

Essentially the compiler finds the file called `stdio.h` and copies and pastes its contents into the code (or the relevant ones at least). This is likely a massive oversimplification, but the central idea remains the same. That's pretty much the whole preprocessing step in a nut shell.

## Compiling

Compiling takes the preprocessed code and converts it into **assembly** code. As you know, this is pretty much as close as you can get to the 0s and 1s that lie underneath everything. Before assembly, people were literally just writing 0s and 1s with punch cards.

In summary, compiling takes C code and converts it to assembly code.

## Assembling

Now we go a step further and convert assembly code to 0s and 1s. Now you're in the deep dark depths of programming pain.

## Linking

This is what links *all* the 0s and 1s together. It pulls all the requirements together (the code in the headers, your code, and everything else) so that they can function as one.
