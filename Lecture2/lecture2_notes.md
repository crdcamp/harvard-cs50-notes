# Links

* [Lecture video](https://www.youtube.com/watch?v=h5Gc1n8ZuU8)
* [Lecture notes](https://cs50.harvard.edu/x/notes/2/)
* [Manual Pages](https://manual.cs50.io/)
* [Problem Set 2]()

# Arrays

We're gonna discuss... well... arrays!

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
