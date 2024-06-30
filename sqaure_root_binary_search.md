# **SQUARE ROOT USING BINARY SEARCH**

## ***Problem statement***
Given an integer n, calculate the absolute square root of n

> **Sample input 1**

Input | Ouput
:---: | :---:
14 | 3

> **Sample input 2**

Input | Ouput
:---: | :---:
25 | 5

Note: `sqrt()` function **is not allowed**

## **Idea**

From 1 to n, cut the distance into half, again and again, until it's not greater than n

For instance: 

```
n = 14
x = n / 2 --> x = 7 
x * x > n --> x = x / 2 = 3
x * x < n --> x = 3 (final solution)
```

## **Implementation**
```cpp
int square_root_floor(int x){
    int low = 1, high = x, ans = -1;
    while (low <= high){
        int mid = (low + high) / 2;
        int msg = mid * mid;
        if (msg == x)
            return mid;
        else if (msg > x)
            high = mid - 1;
        else{
            low = mid + 1; ans = mid;
        }
    }
    return ans;
}
```

> **Time complexity:** $O(\log{n})$