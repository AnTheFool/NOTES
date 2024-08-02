# **PREFIX SUM**

## ***TECHNIQUES***

- Create an array `pref` storing the sum of elements of `arr` from `i` to `j` `(1 <= i < j <= n)`

- `prefix[0] = 0` 

- General formula: `prefix[i] = prefix[i - 1] + arr[i]`

### Code
```cpp
void prefix(int n, int arr[]){
    int prefix[n];
    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + arr[i];
}
```

## ***EQUILIBRIUM POINT***

### ***Problem statement***

Given an array, print the index of the equilibrium point. Equilibrium point is the index that has

## ***MORE PROBLEMS***

- [Breed Counting](https://usaco.org/index.php?page=viewproblem2&cpid=572). View solutions [here](/PREFIX_SUM/breed_counting.cpp)

- [Hoof Paper Scissors](https://usaco.org/index.php?page=viewproblem2&cpid=691). View solutions [here](/PREFIX_SUM/hoof_paper_scissor.cpp)

- [Subsequences Summing to Sevens](https://usaco.org/index.php?page=viewproblem2&cpid=595). View solutions [here](/PREFIX_SUM/div7.cpp)

- [Subarray Sum II](https://cses.fi/problemset/task/1661). View solutions [here](/PREFIX_SUM/subarray_count.cpp)

- [Subarray Divisiblity](https://cses.fi/problemset/task/1662). View solutions [here](/PREFIX_SUM/subarray_divisibility.cpp)