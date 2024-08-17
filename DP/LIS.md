# **LONGEST INCREASING SUBSEQUENCE**

The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.

```
Input: arr[] = {3, 10, 2, 1, 20}
Output: Length of LIS = 3
The longest increasing subsequence is 3, 10, 20

Input: arr[] = {3, 2}
Output: Length of LIS = 1
The longest increasing subsequences are {3} and {2}

Input: arr[] = {50, 3, 10, 7, 40, 80}
Output: Length of LIS = 4
The longest increasing subsequence is {3, 7, 40, 80}
```

# RECURSIVE SOLUTION
## Idea

**Optimal Substructure:** Let $arr[0..n-1]$ be the input array and $L(i)$ be the length of the LIS ending at index i such that $arr[i]$ is the last element of the LIS. Then, $L(i)$ can be recursively written as:

$$
L(i) = 1 + max(L(j)) \text{  where  } 0<j<i \text{  and  } arr[i] < arr[j]; \\ \text{ or } \\ L(i) = 1 \text{  if no such } j \text{  exists  }
$$

To find the LIS for a given array, we need to return $max(L(i))$ where $0 < i < n$. 

Formally, the length of the longest increasing subsequence ending at index $i$, will be 1 greater than the maximum of lengths of all longest increasing subsequences ending at indices before i, where $arr[j] < arr[i] (j < i)$.

Thus, we see the LIS problem satisfies the optimal substructure property as the main problem can be solved using solutions to subproblems.

The recursive tree given below will make the approach clearer
```
Input  : arr[] = {3, 10, 2, 11}
f(i): Denotes LIS of subarray ending at index 'i'

(LIS(1)=1)

      f(4)  {f(4) = 1 + max(f(1), f(2), f(3))}
  /    |    \
f(1)  f(2)  f(3) {f(3) = 1, f(2) and f(1) are > f(3)}
       |      |  \
      f(1)  f(2)  f(1) {f(2) = 1 + max(f(1))}
              |
            f(1) {f(1) = 1}
```

## Naive solution using recursion
```cpp
/* A Naive C++ recursive implementation
of LIS problem */
#include <iostream>
using namespace std;

/* To make use of recursive calls, this
function must return two things:
1) Length of LIS ending with element arr[n-1].
	We use max_ending_here for this purpose
2) Overall maximum as the LIS may end with
	an element before arr[n-1] max_ref is
	used this purpose.
The value of LIS of full array of size n
is stored in *max_ref which is our final result
*/
int _lis(int arr[], int n, int* max_ref)
{
	/* Base case */
	if (n == 1)
		return 1;

	// 'max_ending_here' is length of LIS
	// ending with arr[n-1]
	int res, max_ending_here = 1;

	/* Recursively get all LIS ending with arr[0],
	arr[1] ... arr[n-2]. If arr[i-1] is smaller
	than arr[n-1], and max ending with arr[n-1]
	needs to be updated, then update it */
	for (int i = 1; i < n; i++) {
		res = _lis(arr, i, max_ref);
		if (arr[i - 1] < arr[n - 1]
			&& res + 1 > max_ending_here)
			max_ending_here = res + 1;
	}

	// Compare max_ending_here with the overall
	// max. And update the overall max if needed
	if (*max_ref < max_ending_here)
		*max_ref = max_ending_here;

	// Return length of LIS ending with arr[n-1]
	return max_ending_here;
}

// The wrapper function for _lis()
int lis(int arr[], int n)
{
	// The max variable holds the result
	int max = 1;

	// The function _lis() stores its result in max
	_lis(arr, n, &max);

	// returns max
	return max;
}

/* Driver program to test above function */
int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout <<"Length of lis is "<< lis(arr, n);
	return 0;
}
```

# DYNAMIC PROGRAMMING SOLUTION
## Idea

We can see that there are many subproblems in the above recursive solution which are solved again and again. So this problem has Overlapping Substructure property and recomputation of same subproblems can be avoided by either using Memoization or Tabulation.

The simulation of approach will make things clear:

```
Input  : arr[] = {3, 10, 2, 11}
LIS[] = {1, 1, 1, 1} (initially)
```

Iteration-wise simulation : 
```
arr[2] > arr[1] {LIS[2] = max(LIS [2], LIS[1]+1)=2}
arr[3] < arr[1] {No change}
arr[3] < arr[2] {No change}
arr[4] > arr[1] {LIS[4] = max(LIS [4], LIS[1]+1)=2}
arr[4] > arr[2] {LIS[4] = max(LIS [4], LIS[2]+1)=3}
arr[4] > arr[3] {LIS[4] = max(LIS [4], LIS[3]+1)=3}
```

We can avoid recomputation of subproblems by using tabulation as shown in the below code: 

```cpp
#include <iostream>
#include <string.h>
using namespace std;

int LIS( int arr[], int n )  
{  
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++ )  { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j])  
                lis[i] = max(lis[i], lis[j] + 1);  
    }
    int res = lis[0];
    for(int i=0;i<n;i++){
        res = max(lis[i], res);
    }
    return res;
}  

int main() {
    int arr[] ={3, 4, 2, 8, 10, 5, 1};
    int n = 7;
    cout<<LIS(arr, n);
}
```

## **$O(n\log{n})$ solution**

Consider an input array A = {2, 5, 3}. I will extend the array during explanation.

By observation we know that the LIS is either {2, 3} or {2, 5}. Note that I am considering only strictly increasing sequences.

Let us add two more elements, say 7, 11 to the array. These elements will extend the existing sequences. Now the increasing sequences are {2, 3, 7, 11} and {2, 5, 7, 11} for the input array {2, 5, 3, 7, 11}.

Further, we add one more element, say 8 to the array i.e. input array becomes {2, 5, 3, 7, 11, 8}. Note that the latest element 8 is greater than smallest element of any active sequence (will discuss shortly about active sequences). How can we extend the existing sequences with 8? First of all, can 8 be part of LIS? If yes, how? If we want to add 8, it should come after 7 (by replacing 11).

Since the approach is offline (what we mean by offline?), we are not sure whether adding 8 will extend the series or not. Assume there is 9 in the input array, say {2, 5, 3, 7, 11, 8, 7, 9 ...}. We can replace 11 with 8, as there is potentially best candidate (9) that can extend the new series {2, 3, 7, 8} or {2, 5, 7, 8}.

Our observation is, assume that the end element of largest sequence is E. We can add (replace) current element A[i] to the existing sequence if there is an element A[j] (j > i) such that E < A[i] < A[j] or (E > A[i] < A[j] - for replace). In the above example, E = 11, A[i] = 8 and A[j] = 9.
In case of our original array {2, 5, 3}, note that we face same situation when we are adding 3 to increasing sequence {2, 5}. I just created two increasing sequences to make explanation simple. Instead of two sequences, 3 can replace 5 in the sequence {2, 5}.

I know it will be confusing, I will clear it shortly!

The question is, when will it be safe to add or replace an element in the existing sequence?

Let us consider another sample A = {2, 5, 3}. Say, the next element is 1. How can it extend the current sequences {2, 3} or {2, 5}. Obviously, it can't extend either. Yet, there is a potential that the new smallest element can be start of an LIS. To make it clear, consider the array is {2, 5, 3, 1, 2, 3, 4, 5, 6}. Making 1 as new sequence will create new sequence which is largest.

The observation is, when we encounter new smallest element in the array, it can be a potential candidate to start new sequence.

From the observations, we need to maintain lists of increasing sequences.
In general, we have set of active lists of varying length. We are adding an element A[i] to these lists. We scan the lists (for end elements) in decreasing order of their length. We will verify the end elements of all the lists to find a list whose end element is smaller than A[i] (floor value).

Our strategy determined by the following conditions:

```
1. If A[i] is smallest among all end candidates of active lists, we will start new active list of length 1.
2. If A[i] is largest among all end candidates of active lists, we will clone the largest active list, and extend it by A[i].
3. If A[i] is in between, we will find a list with largest end element that is smaller than A[i]. Clone and extend this list by A[i]. We will discard all other lists of same length as that of this modified list.
```

Note that at any instance during our construction of active lists, the following condition is maintained.

"end element of smaller list is smaller than end elements of larger lists".

It will be clear with an example, let us take example from wiki {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}. 

```
A[0] = 0. Case 1. There are no active lists, create one.
0.
-----------------------------------------------------------------------------
A[1] = 8. Case 2. Clone and extend.
0.
0, 8.
-----------------------------------------------------------------------------
A[2] = 4. Case 3. Clone, extend and discard.
0.
0, 4.
0, 8. Discarded
-----------------------------------------------------------------------------
A[3] = 12. Case 2. Clone and extend.
0.
0, 4.
0, 4, 12.
-----------------------------------------------------------------------------
A[4] = 2. Case 3. Clone, extend and discard.
0.
0, 2.
0, 4. Discarded.
0, 4, 12.
-----------------------------------------------------------------------------
A[5] = 10. Case 3. Clone, extend and discard.
0.
0, 2.
0, 2, 10.
0, 4, 12. Discarded.
-----------------------------------------------------------------------------
A[6] = 6. Case 3. Clone, extend and discard.
0.
0, 2.
0, 2, 6.
0, 2, 10. Discarded.
-----------------------------------------------------------------------------
A[7] = 14. Case 2. Clone and extend.
0.
0, 2.
0, 2, 6.
0, 2, 6, 14.
-----------------------------------------------------------------------------
A[8] = 1. Case 3. Clone, extend and discard.
0.
0, 1.
0, 2. Discarded.
0, 2, 6.
0, 2, 6, 14.
-----------------------------------------------------------------------------
A[9] = 9. Case 3. Clone, extend and discard.
0.
0, 1.
0, 2, 6.
0, 2, 6, 9.
0, 2, 6, 14. Discarded.
-----------------------------------------------------------------------------
A[10] = 5. Case 3. Clone, extend and discard.
0.
0, 1.
0, 1, 5.
0, 2, 6. Discarded.
0, 2, 6, 9.
-----------------------------------------------------------------------------
A[11] = 13. Case 2. Clone and extend.
0.
0, 1.
0, 1, 5.
0, 2, 6, 9.
0, 2, 6, 9, 13.
-----------------------------------------------------------------------------
A[12] = 3. Case 3. Clone, extend and discard.
0.
0, 1.
0, 1, 3.
0, 1, 5. Discarded.
0, 2, 6, 9.
0, 2, 6, 9, 13.
-----------------------------------------------------------------------------
A[13] = 11. Case 3. Clone, extend and discard.
0.
0, 1.
0, 1, 3.
0, 2, 6, 9.
0, 2, 6, 9, 11.
0, 2, 6, 9, 13. Discarded.
-----------------------------------------------------------------------------
A[14] = 7. Case 3. Clone, extend and discard.
0.
0, 1.
0, 1, 3.
0, 1, 3, 7.
0, 2, 6, 9. Discarded.
0, 2, 6, 9, 11.
----------------------------------------------------------------------------
A[15] = 15. Case 2. Clone and extend.
0.
0, 1.
0, 1, 3.
0, 1, 3, 7.
0, 2, 6, 9, 11.
0, 2, 6, 9, 11, 15. <-- LIS List
----------------------------------------------------------------------------
```

## Code solution

View solutions [here](/DP/lis.cpp)

# **VARIATIONS OF LIS**

