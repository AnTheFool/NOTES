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