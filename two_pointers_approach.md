# **TWO POINTERS APPROACH**

## ***Example problem***

Find if there is a pair with sum equals `x` in a **sorted array**

Input | Output
|:--:|:--:|
2, 5, 8, 12, 30; x = 17 | True
3, 8, 13, 18;    x = 14 | False

## **Naive solution**
Pseudocode
```
for i = 0 --> n - 1:
    for j = i + 1 --> n:
        if arr[i] + arr[j] == x
            return true
return false
```

## **Two pointers approach**

- Set `i = 0, j = n - 1`

- We move `i` and `j` towards each other.

Pseudocode
```
i = 0, j = n - 1
if arr[i] + arr[j] == x:
    return True
else if arr[i] + arr[j] > x:
    j = j - 1
else:
    i = i + 1
```

Full code:
> CPP:
```cpp
bool isPair(int arr[], int n, int x){
    int i = 0, j = n - 1;
    while (i < j){
        if (arr[i] + arr[j] == x)
            return true;
        else if (arr[i] + arr[j] < x)
            i++;
        else
            j--;
    }
    return false;
}
```

> Python:
```py
def isPair(arr, n, x):
    i, j = 0, n - 1
    while i < j:
        if arr[i] + arr[j] == x:
            return True
        elif arr[i] + arr[j] < x:
            i += 1
        else:
            j -= 1
    return False
```