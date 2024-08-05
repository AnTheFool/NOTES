# CHECK KTH BIT IS SET OR NOT

Check if the k-th bit (from right to left) exist in the binary representation of number `n` or not.

### For example: 

```
Input: n = 5, k = 1
Output: Yes
Explanation: 5 has binary representation of 101 --> kth bit exists --> print YES

Input: n = 8, k = 2
Output: Yes
Explanation: 8 has binary representation of 1000 --> kth bit doesn't exist --> print NO
```

## **Method 1: Left shift operator**

```cpp
void kthbit(int n, int k){
    if (n & (1 << (k - 1)) != 0)
        cout << "YES";  
    else
        cout << "NO";
}
```

## **Method 2: Right shift operator**
```cpp
void kthbit(int n, int k){
    if ((n >> (k - 1) & 1) == 1)
        cout << "YES";
    else
        cout << "NO";
}
```