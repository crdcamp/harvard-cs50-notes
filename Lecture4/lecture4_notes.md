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
