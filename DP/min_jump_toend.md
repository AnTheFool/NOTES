# MINIMUM JUMPS TO REACH THE END

Given an array `arr[]` where each element represents the max number of steps that can be made forward from that index. The task is to find the minimum number of jumps to reach the end of the array starting from index 0. If the end isn’t reachable, return -1.

**Examples:**

```
Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 9 -> 9)
Explanation: Jump from 1st element to 2nd element as there is only 1 step.
Now there are three options 5, 8 or 9. I
f 8 or 9 is chosen then the end node 9 can be reached. So 3 jumps are made.

Input:  arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
Output: 10
Explanation: In every step a jump is needed so the count of jumps is 10.
```

## Recursion

- Create an array `minJumps(i)` that tells the minimum number of jumps required to reach the last index from `i`.

- Transition: From each index `i`, we can jump to any index in the range `[i, i + a[i]]`

```cpp
#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n){
    if (n == 1)
        return 0;

    int res = INT_MAX;
    for (int i = n - 2; i >= 0; i--) {
        if (i + arr[i] >= n - 1) {
            int sub_res = minJumps(arr, i + 1);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }
 
    return res;
}

int main(){
    int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of jumps to";
    cout << " reach the end is " << minJumps(arr, n);
    return 0;
}
```

## DP

It can be observed that there will be overlapping subproblems. 

For example in array, `arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} minJumps(3, 9)` will be called two times as `arr[3]` is reachable from `arr[1]` and `arr[2]`. So this problem has both properties (optimal substructure and overlapping subproblems) of Dynamic Programming.

Follow the below steps to implement the idea:

- Create `jumps[]` array from left to right such that `jumps[i]` indicate the minimum number of jumps needed to reach `arr[i]` from `arr[0]`.
- To fill the jumps array run a nested loop inner loop counter is `j` and the outer loop count is `i`.
    - Outer loop from 1 to `n-1` and inner loop from 0 to `i`.
    - If `i` is less than `j + arr[j]` then set `jumps[i]` to minimum of `jumps[i]` and j`umps[j] + 1`. initially set `jump[i]` to `INT_MAX`
- Return `jumps[n-1]`.

```cpp
// C++ program for Minimum number
// of jumps to reach end
#include <bits/stdc++.h>
using namespace std;

int min(int x, int y) { return (x < y) ? x : y; }

int minJumps(int arr[], int n){
	int* jumps = new int[n];
	int i, j;

	if (n == 0 || arr[0] == 0)
		return INT_MAX;

	jumps[0] = 0;
  
	for (i = 1; i < n; i++) {
		jumps[i] = INT_MAX;
		for (j = 0; j < i; j++) {
			if (i <= j + arr[j] && jumps[j] != INT_MAX) {
				jumps[i] = min(jumps[i], jumps[j] + 1);
				break;
			}
		}
	}
	return jumps[n - 1];
}

int main(){
	int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
	int size = sizeof(arr) / sizeof(int);
	cout << "Minimum number of jumps to reach end is "
		<< minJumps(arr, size);
	return 0;
}
```
