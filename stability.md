# **STABILITY IN SORTING ALGORITHM**

## ***Go through the example***

Suppose we already have a stable array like this

```
a = [('An', 10), ('Bao', 50), ('Nguyen', 10), ('Tin', 50)]
```

This array has already been sorted alphabetically increasing. Now, we want to sort this array based on the marks, and if any of them having the same marks, sort their names increasing alphabetically $\rightarrow$ we call it **stability**

So, what does **stability** here mean? 
> A sorting algorithm is said to be stable if two objects with equal keys appear in the ***same order*** in sorted output as they appear in the input data set

Back to example, here's how to sort the array stably:
```
a = [('An', 10), ('Nguyen', 10), ('Bao', 50), ('Tin', 50)]
```

### Notes: Sorting arrays with only integers doesn't need to care about stability, as all keys are different.

## ***Examples of sorting algorithm***

### *Stable algorithm*
- Bubble sort

- Insertion sort

- Merge sort

### *Unstable algorithm*
- Selection sort

- Quick sort

- Heap sort