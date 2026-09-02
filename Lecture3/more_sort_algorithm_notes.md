Before beginning, let's review the sorting algorithms we have at out disposal.

# Selection Sort

In selection sort, the idea of the algorithm is to **find the smallest unsorted element and add it to the end of the sorted list**.

In pseudocode:
* Repeat until no unsorted elements remain:
    * Search the unsorted part of the data to find the smallest value.
    * Swap the smallest found value with the first element of the unsorted part.

* **Worst-case scenario:** We have to iterate over each of the `n` elements of the array (to find the smallest unsorted element) and we must repeat this process `n` times, since only one element gets sorted on each pass.
* **Best-case scenario:** Exactly the same. There's no way to guarantee the array is sorted until we go through this process for all the elements.

The first time iterating through the list takes `n - 1` steps. The second time, it takes `n - 2`, and so on. This can be represented as:

```(n - 1) + (n - 2) + (n - 3) + ... + 1```

This could be simplified to n(n-1)/2 or, more simply, 𝑂⁡(𝑛^2). In the worst case or upper bound, selection sort is in the order of 𝑂⁡(𝑛^2). In the best case or lower bound, selection sort is in the order of Ω⁡(𝑛^2).

Therefore, the time it takes for this algorithm increases exponentially with `n` number of elements. Not good!

# Bubble Sort

In bubble sort, the idea of the algorithm is to move higher values elements generally towards the right and lower value elements towards the left.

In pseudocode:
* Set swap counter to a **non-zero** value
* Repeat until the swap counter is 0:
    * Reset swap counter to 0
    * Look at each adjacent pair
        * If two adjacent elements are not in order, swap them and add one to the swap counter

Bit of a weird way to express this. Let's show the pseudocode from the notes instead of the video to get a clearer picture.

```pseudo
Repeat n-1 times
    For i from 0 to n-2
        If numbers[i] and numbers[i+1] out of order
            Swap them
        If no swaps
            Quit
```

As we further sort the array, we know more and more of it becomes sorted, so we only need to 3look at the pairs of numbers that haven't been sorted yet (implying a faster run time than selection sort).

Moreover, we set the swap counter to a non-zero value since if we set it to 0 the program would just automatically quit.

Bubble sort can be analyzed as follows:
* (𝑛 −1) ×(𝑛 −1)
* 𝑛2 −𝑛 −𝑛 +1
* 𝑛2 −2⁢𝑛 +1
* or, more simply 𝑂⁡(𝑛2).

**In the worst case or upper bound**, bubble sort is in the order of 𝑂⁡(𝑛^2). **In the best case or lower bound**, bubble sort is in the order of Ω⁡(𝑛).

So, bubble sort has the potential to be faster than selection sort since selection sort's bounds are equal.

You can refer to [this video](https://www.youtube.com/watch?v=RT-hUXUWQ2I&t=123s) to get a nice visual on how this works.

# Merge Sort

The most efficient (and complicated) algorithm we've been introduced to thus far. In merge sort, the idea of the algorithm is to sort smaller arrays and then combine those arrays together (merge them) in sorted order.

Merge sort leverages **recursion** as well.

The pseudocode (from the video) for merge sort is as follows:

* Sort the left half of the array (assuming n > 1)
* Sort the right half of the array (assuming n > 1)
* Merge the two halves together

The pseudocode (from the notes) for merge sort is like this:

```pseudo
If only one number (base case)
    Quit
Else
    Sort left half of numbers
    Sort right half of numbers
    Merge sorted halves
```

Consider the following list of numbers:

```6341```

First, merge sort asks "Is this one number?" The answer is "no", so the algorithm continues.

```6341```

Second, merge sort will now split the numbers down the middle (or as close as it can get) and sort the left hald of numbers.

```63|41```

Third, merge sort would look at these numbers on the left half and ask, "Is this one number?" Since the answer is "no", it would then split the numbers on the left half down the middle.

```6|3```

Fourth, merge sort will again ask, "Is this one number?" The answer is yes this time. Therefore, it will quit this task and return to the last task it was running at this point:

```63|41```

Fifth, merge sort will sort the numbers on the left.

```36|41```

Now, we return to where we left off in the pseudocode now that the left side has been sorted. A similar process of steps 3-5 will occur with the right-hand numbers. This will result in:

```36|14```

Both halves are now sorted. Finally, the algorithm will merge both sides. It will look at the first number on the left and the first number on the right. It will put the smaller number first, then the second smallest. The algorithm will repeat this for all numbers, resulting in:

```1346```

Program exits.

Merge sort is a very efficient sort algorithm with a worst case of 𝑂⁡(𝑛⁢log⁡𝑛). The best case is still Ω⁡(𝑛⁢log⁡𝑛) because the algorithm still must visit each place in the list. Therefore, merge sort is also Θ⁡(𝑛⁢log⁡𝑛) since the best case and worst case are the same.

[Here's the video](https://www.youtube.com/watch?v=Ns7tGNbtvV4&time_continue=125&source_ve_path=NzY3NTg&embeds_widget_referrer=https%3A%2F%2Fcs50.harvard.edu%2F&embeds_referring_euri=https%3A%2F%2Fvideo.cs50.io%2F&embeds_referring_origin=https%3A%2F%2Fvideo.cs50.io) on merge sort, and [here's a better one](https://www.youtube.com/watch?v=3j0SWDX4AtU) that goes beyond just four numbers to help you actually understand it.

# random5000.txt

`random5000.txt` contains 5000 `int`s in random order.

**./sort1 random5000.txt**

This command appears to sort the `int`s from least to greatest. Moreover, the resulting sort seems to confirm that the numbers do indeed range from 1-5000, and are in fact not just random `int`s, but instead are `int`s that are randomly ordered.

**./sort2 random5000.txt**

At first glance, `sort2` appears to do the same thing as `sort1` regarding `random5000.txt`. However, `sort2` does seem to run faster. In comparison, `sort1` is printing out the numbers in a seemingly linear manner, one by one. `sort2` does not seem to printing the numbers in this way.

What it we were to time both of these using a bash command?

(For what it's worth, I proudly came to this conclusion before reading the notes that say to do this!)

## `sort1` vs. `sort2` time on `random5000.txt`

Running `time ./sort1 random5000.txt` results in the following times:

```bash
real    0m0.071s
user    0m0.048s
sys     0m0.017s
```

Running `time ./sort2 random5000.txt` results in the following times:


```bash
real    0m0.028s
user    0m0.005s
sys     0m0.020s
```

When only considering `real` time (since that's the only one we care about), `sort2` is indeed running considerably faster (about twice as fast) than `sort1`.


YOU CAN DETERMINE THE ALGORITHM TYPE BY COMPARING THE RUN TIMES BASED ON THE DATA SET SIZE!
