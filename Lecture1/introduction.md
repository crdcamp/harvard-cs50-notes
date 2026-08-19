# 8 Bit Calculation Cheatsheet

It's pretty simple. Just sum the corresponding numbers where the bit is equal to 1 to determine the number or letter.

![8 Bit Calculation Cheatsheet](images/8bit_calculation_cheatsheet.png)

A good way to remember the numbers that each of the 8 bits correspond is by starting at the right with 1 and keep multiplying by 2 as you go to the left.

# ASCII Character Bits Cheatsheet

Each ASCII character is given its own identifying number. You can use the above 8 bit formula to determine which bit pattern corresponds to which letter.

![ASCII Character Bits Cheatsheet](images/ASCII_cheatsheet.png)

Note that uppercase characters begin at **65(A)**, and lowercase characters begin at **97(a)**.

All uppercase and lowercase ASCII characters are 32 away from each other. Essentially, the only character/number you need to know is A at 65. You can figure out the rest of this logic from there. 

Moreover, this means that you can just flip the bit that corresponds to 32 (the third bit from the left when dealing with bytes) to convert between uppercase and lowercase.

# Exercise

What pattern of 0s and 1s do these three bytes represent?

![Exercise1](images/bits_to_ASCII_exercise.png)

* The bytes represent the following numbers: 72, 73, 33
* According to our lil cheatsheet, these numbers represent the following ASCII characters: H, I, !

To summarize, these bytes represent "HI!"

# Unicode

Unicode is essentially an extension of ASCII where more bits were added in order to express more characters for more languages (this includes emojis as well).

# RGB

Similar to how ASCII was developed, RGB is a standardized set of numbers that represent different colors. These colors are mixed together in order to achieve various colors. 

* Each RGB color ranges 0 to 255.
* 0, 0, 0 corresponds to black.
* 255, 255, 255 corresponds to white.

**Where are these colors coming from?**

Each color is assigned to a pixel in order to create an image.

**What about animation?**

It's just a bunch of images/frames one after another (like a flip book).

# Audio

Each note can be represented by numbers as well. All you need is a way to interpret them.

# Algorithms

As you know, a big focus on algorithms is efficiency and using the minimal amount of computation or even financial resources.

In the lecture, the professor uses a phone book as an example. To find a contact, we can iterate one page at a time, yet this obviously inefficient. Instead, we can keep dividing the phone book in half to more efficiently find the contact we're looking for.

The time to solve the first example would look something like this:

![graph1](images/time_to_solve_graph1.png)

As you can see, the time to solve increases far faster than the size of the problem.

However, when we start dividing the data, we get this:

![graph1](images/time_to_solve_graph2.png)

It's still a straight line, but it's about twice as fast.

However, if we solved the problem logarithmically, the results are MUCH better:


![graph1](images/time_to_solve_graph3.png)

Pretty simple stuff, but definitely a lot more technical in practice. This ties back to a theme in the lecture where the professor states that **code is just an implementation of an algorithm to solve a problem** (things you kinda already knew).
