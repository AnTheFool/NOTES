# **OVERVIEW OF SORTING**
## 1. Binary array
Use partition of **Quicksort** (Lomato, Hoare, Naive), in which Lomato and Hoare are *faster* than Naive, but Naive is *stabler*

## 2. Array with three values
We can also use partition of **Quicksort** (Lomato, Hoare, Naive)

## 3. Array of size `n` and small ranged value
- Optimal algorithm: **Counting sort**
- Memory complexity: $O(k)$
- Time complexity: $O(n + k)$

## 4. Array of size `n` and range is of size $n^2$ or $n^3$ or closer
- Optimal algorithm: **Radix sort**
- Memory complexity: $O(n)$
- Time complexity: $O(n)$

## 5. Array of uniformly distributed data over a range
> *What does it mean by uniformly distributed? Welp, imagine your array has max = 1.0 and min = 0.0. And then you have hundreds/thousands of values in there which are unidentical, like 0.4123, 0.3212, etc. That's how uniformly distributed means*
- Optimal solution: **Bucket sort**
- Memory complexity: $O()$
- Time complexity: $O(n)$ on average

## 6. When memory writes are costly
- Optimal algorithm: **Selection sort/Cycle sort**
- Time complexity: 
    * Worse case: $O(n^2)$
    * Best case: $O(n^2)$

## 7. When only adjacent swaps are allowed
- Normally use **Bubble sort**
- But more optimal, we can use **Cocktail sort**

## 8. When array size is small:
- **Insertion sort** works best
- Other optimal sorts: selection sort

## 9. When available extra model is small
- Optimal sort: **Shell sort**  
- Time complexity: $O(n\times \log^2(n))$

## 10. Other cases when you do not know anything about the array (or, in other words, GENERAL CASES)

- There are: MergeSort, HeapSort and QuickSort

- MergeSort and HeatSort takes $O(n\log{n})$ on average and on worst case.

- QuickSort takes $O(n^2)$ in worst case but works better than those two on average.

- MergeSort is stable $\rightarrow$ works really well with **Linked lists**

- MergeSort + QuickSort works on **Divide and Conquer** concept

### Hybrid sorting
- TimSort = MergeSort + InsertionSort

- IntraSort = QuickSort + HeapSort + InsertionSort