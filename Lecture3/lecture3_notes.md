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
