# **ONE ODD OCCURING**

Given an array of positive integers. All numbers occur an even number of times except one number which occurs an odd number of times. Find the number in $O(n)$ time & constant space.

## ***Naive solution***

A Simple Solution is to run two nested loops. The outer loop picks all elements one by one and the inner loop counts the number of occurrences of the element picked by the outer loop. The time complexity of this solution is $O(n^2)$.

```cpp
// C++ program to find the element
// occurring odd number of times
#include <bits/stdc++.h>
using namespace std;

// Function to find the element
// occurring odd number of times
int getOddOccurrence(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++) {
        int count = 0;
        for (int j = 0; j < arr_size; j++) {
            if (arr[i] == arr[j])
                count++;
        }
        if (count % 2 != 0)
            return arr[i];
    }
    return -1;
}

// driver code
int main()
{
    int arr[] = { 2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    // Function calling
    cout << getOddOccurrence(arr, n);
    return 0;
}
```

## ***Efficient solution***

The Best Solution is to do bitwise XOR of all the elements. XOR of all elements gives us odd occurring elements. 

```cpp
// C++ program to find the element
// occurring odd number of times
#include <bits/stdc++.h>
using namespace std;

// Function to find element occurring
// odd number of times
int getOddOccurrence(int ar[], int ar_size)
{
	int res = 0;
	for (int i = 0; i < ar_size; i++)	
		res = res ^ ar[i];
	return res;
}

/* Driver function to test above function */
int main()
{
	int ar[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
	int n = sizeof(ar)/sizeof(ar[0]);
	// Function calling
	cout << getOddOccurrence(ar, n);	
	return 0;
}
```

# **VARIATION QUESTION**

Given an array of $n$ numbers that has values in range $[1, n + 1]$. Every number appears exactly one, except one number is missing. Find the missing number.

Ex:
```
Input: arr[] = [1, 4, 3]
OutputL 2

Input: arr[] = [1, 5, 3, 2]
Output: 4
```

The idea can be sketched into a formula like this:

$$
\text{missing number } = (1\wedge2\wedge3\wedge\ldots\wedge(n + 1))\wedge(arr[0]\wedge arr[1]\wedge arr[2]\wedge\ldots\wedge arr[n - 2])
$$