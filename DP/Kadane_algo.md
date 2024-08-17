# Kadane's Algorithm - I

Kadane's algorithm comes into picture when we want to find the maximum possible sum in an array when summing the contiguous elements of the array.

You are given an array. Find the maximum possible sum of contiguous elements of the array ending at each position in the array. Also, return the overall maximum that we can achieve.

### Example 1
```
Input:
N = 6
arr[] = {5,-2,-3,32,-5,65}
Output: 5 3 0 32 27 92
        92
Explanation: Maximum sum at each index is 5, 3, 0, 32, 27, 92. And, maximum sum for contiguous array is 92.
```

### Example 2

```
Input:
N = 5
arr[] = {-9,-8,8,3,-4}
Output: -9 -8 8 11 7
         11
```

# SOLUTION CODE

```cpp
long long maximumSum(int arr[], int sizeOfArray)
{
    long long dp[sizeOfArray];
    dp[0] = arr[0];
    long long ans = dp[0];
    for (int i = 1; i < sizeOfArray; i++){
        dp[i] = max(dp[i - 1] + (long long)arr[i], (long long)arr[i]);
        ans = max(dp[i], ans);
    }
    for (int i = 0; i < sizeOfArray; i++)
        cout << dp[i] << " ";
    cout << "\n";
    return ans;
}
```