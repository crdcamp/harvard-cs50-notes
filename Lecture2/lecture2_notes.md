# Links

* [Lecture video](https://www.youtube.com/watch?v=h5Gc1n8ZuU8)
* [Lecture notes](https://cs50.harvard.edu/x/notes/2/)
* [Manual Pages](https://manual.cs50.io/)
* [Problem Set 2](https://cs50.harvard.edu/x/psets/2/)

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

`make` is not technically the compiler itself. The compiler you've been using is actually called `clang`, for "C language". What `make` is really doing is running:

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

# Data Types

Here's a quick overview of some data types and their bit/byte usage:

```
bool    1 byte
int     4 bytes
long    8 bytes
float   4 bytes
double  8 bytes
char    1 byte
string  ?
```

* A bool, even though is could just be represented as a 0 or 1, takes up a byte for a multitude of reasons, but it's mainly because it's easier and more efficient at the end of the day.
* A string is undetermined because, obviously, a string can be any length.

Refer to the [Lecture video](https://www.youtube.com/watch?v=h5Gc1n8ZuU8) (at around 1 hour 5 minutes) for more information on how bytes are literally/physically stored in memory.

## Working with Floats

Consider the following program:

```c
#include <stdio.h>

int main(void) {
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;

    printf("Average: %i\n", (score1 + score2 + score3) / 3);
}
```

This will compile, but the result will be truncated, since we're trying to divide `int`s, not `float`s. You already know this, but here's where the professor drops some serious knowledge:

```c
#include <stdio.h>

int main(void) {
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;

    // Changed `%i` to `%f`
    // Casted the divisor as a float
    printf("Average: %f\n", (score1 + score2 + score3) / (float) 3); // Can also use `3.0` to have it treated as a float
}
```

While you could manually change each `int` to be declared as a `float`, this is unnecessary. Turns out, if you divide `int`s by a `float`, the `int`s are automatically treated as a `float`! I wouldn't have expected this from C, so that's pretty nice.

Also, as a quick aside, it makes a bit more sense semantically (and for clarity) to cast 3 as a `float`, rather than just stating it as 3.0.

NOW... as you've noticed, declaring variables like we did with these `int`s is stupid and inefficient. Thus, we finally get to talk about arrays.

# Arrays

This is where things start getting a bit more tricky in C when is comes to managing your data. When you declare an array, you have to specify its length. So, if we wanted an array to store three scores, we'd have to declare it like this:

```c
int scores[3];
```

Now let's implement this:

```c
#include <stdio.h>

int main(void) {
    int scores[3];
    scores[0] = 72
    scores[1] = 73
    scores[2] = 33

    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / (float) 3);
}
```

Now let's clean it up a bit with the `get_int()` from CS50, a loop, and an average function:

```c
#include <cs50.h> // Using `get_int()` now
#include <stdio.h>

float average(int length, int numbers[]);

int main(void) {
    // `const`s are typically capitalized just to better
    // visually communicate that you're declaring a constant
    const int N = 3; // `const` because `N` isn't changing
    int scores[N];
    for (int i = 0; i < N; i++) {
        scores[i] = get_int("Score: ");
    }
    
    printf("Average: %f\n", average(N, scores)); // We're assuming we already have an average function here
}

float average(int length, int numbers[]) {
    int sum = 0;  
    for (int i = 0; i < length; i++) {
        sum += numbers[i];
    }

    return sum / (float) length;
}
```

## Chars, Arrays, and Strings

As you already concluded, a `string` is just an array of `char`s.

Here's a quick demonstration:

```c
#include <cs50.h>
#include <stdio.h>

int main(void) {
    string s = "HI!";
    printf("%c %c %c\n", s[0], s[1], s[2]);
    // To show the ASCII values:
    printf("%i %i %i\n", s[0], s[1], s[2]);
}
```

Now, what would happen if we extend beyond the used indices of the string like this?

```c
#include <cs50.h>
#include <stdio.h>

int main(void) {
    string s = "HI!";
    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);
}
```

This would result in:

```bash
72 73 33 0
```

The fourth byte in the computer's memory is 0 by design. The compiler automatically terminates any string put in double quotes with a pattern of 8 zero bits (or a byte). This is represented as `\0`, which directly translates to the former. This is called the **nul character**, which always represents the end of a string.

This means that a string of three `char`s would actually take up 4 bytes instead of three. Also, you remember how you were wondering why we're declaring array lengths that are seemingly greater than the number of `char`s were using (since indexing always starts at 0)? Well... this is why. The array needs that extra space for the `\0`.

Beyond just making an array of `char`s, you can also make an array of `string`s:

```c
#include <cs50.h>
#include <stdio.h>

int main(void) {
    string words[2];

    words[0] = "HI!";
    words[1] = "BYE!";

    printf("%s\n", words[0]);
    printf("%s\n", words[1]);
}
```

Now you have the ability to use two brackets to access both the `string` values and their `char` values like so:

```c
printf("%c%c\n", words[0][1]);
```

As a final point, you can use `{}` to specify the values in an array without having to individually declare them.

**Note:** There's also no need to declare the size of the array either.

```c
#include <cs50.h>
#include <stdio.h>

int main(void) {
    const int N = 3;
    int scores[] = {72, 73, 33};
}
```

## Finding the Length of a String

Consider the following example:

```c
#include <cs50.h>
#include <stdio.h>

int main(void) {
    string name = get_string("Name: ");
    int n = 0;

    // Simply count until you reach the null character
    while (name[n] != '\0') {
        n++;
    }
    printf("%i\n", n);
}
```

Pretty self explainable. No need for additional notes here.

To avoid the need to always create a custom function like this, you can instead import `string.h` and use `strlen`. `string.h` contains a bunch of functions for handling strings. You can find a class manual for this [here](https://manual.cs50.io/#string.h).

Here's how you can use `strlen` (it's incredibly simple):


```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    string name = get_string("Name: ");

    printf("%i\n", strlen(name));
}
```

# Declaring Multiple Variables in a Loop

Here's something you're going to want to use eventually. Let's start with a bad example:

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    string s = get_string("Input: ");

    for (int i = 0; i < strlen(s); i++) {
        printf("%c", s[i]);
    }
    printf("\n")
}
```

In this code, we're calculating the length of the string every time we iterate through the loop. This is retarded. Don't do this.

Now the first fix that came to mind was declaring `strlen(s)` before the loop:

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    string s = get_string("Input: ");
    length = strlen(s);
    
    for (int i = 0; i < length; i++) {
        printf("%c", s[i]);
    }
    printf("\n")
}
```

While this is certainly better, we have a third option where we can declare multiple variables within the for loop's arguments like so:

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    string s = get_string("Input: ");
    
    for (int i = 0, length = strlen(s); i < length; i++) {
        printf("%c", s[i]);
    }
    printf("\n")
}
```

This is a much cleaner way to do this, and I have a feeling that you'll want to use it in whatever assignment is coming up. Note that you don't declare the variable type after `int i = 0` since **this syntax only allows one data type**. If you need a different data type, you're out of luck. It's also worth mentioning that pretty much any compiler would fix the issue in the first bad example code, but you know... ya love best practices.

# ctype Library

I didn't write this part down, but the professor converted letters to uppercase by subtracting 32 from a `char` value. You can accomplish this much more simply and with much less code using the `ctype.h` library:

```c
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    string s = get_string("Input: ");
    
    for (int i = 0, length = strlen(s); i < length; i++) {
        if (islower(s[i])) {
            printf("%c", toupper(s[i]));
        }
    }
    printf("\n")
}
```

There's no need for an else statement because `islower()` and `isupper()` already handle that case.

# main

`main` is the function that will be called **automatically**. It's a standardized function.

As you know, `void` means that the function does not intake arguments. This is obviously not the case for every `main` function. You can define multiple `main` arguments like this:

```c
#include <stdio.h>

int main(int argc, string argv[]) {
    ...
}
```

By convention, we use `argc` (the count of the arguments) and `argv` (the argument vector aka array of strings).

Now we can write programs that have command line arguments like so:

```c
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) {
    printf("hello, %s\n", argv[1]);
}
```

We did `argv[1]` instead of `argv[0]` **because `argv[0]` automatically contains the program's own name**. You can use this to refer to your own project in outputs.

Also a quick reminder that `argc` contains the number of arguments. **The first argument is always the program name**, which is why we're specifying `if (argc != 2)`. So if you want to require a single argument from the user you could do it like this: 

```c
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) {
    if (argc != 2) { // `argc == 1` is the program name
        printf("hello, %s\n", argv[1]);
    }
    else {
        pritnf("hello, world\n");
    }
}
```

Then (after compiling the program) you can pass an argument in your terminal like so:

```bash
./greet Christian
```

Importantly, and for some reason that I can't understand, **C only allows these two arguments in the main function**. Apparently it's just "because" according to the professor. The guy who made the language just decided that would be how it is. You might want to look more into this another time.

# Exit Status

By convention, `main` returns `0` if it executed successfully. Any other number is considered an error determined arbitrarily by whoever designed the program.

Here's an example:

```c
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Missing command-line argument");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}
```

You can use `echo $?` to see the return value to see what your code returned. You can use `./status` followed by inputs (or no inputs) to check the return code of the previous execution.
