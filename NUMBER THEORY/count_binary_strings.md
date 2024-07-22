# **COUNT BINARY STRINGS WITH NO CONSECUTIVE 1S**

## ***PROBLEM STATEMENT***

Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1's.

For example:
```
Input: n = 2
Output: 3
// The 3 strings are 00, 01, 10
```

```
Input: N = 3
Output: 5
// The 5 strings are 000, 001, 010, 100, 101
```

## ***IDEA AND SOLUTION***

A binaryy string, with the given constraints, would end with:
1. 00
2. 01 or 10

Recursive function: 
$\begin{gather}
\text{count}(n) = \text{count}(n - 1) + \text{count}(n - 2)
\end{gather}
\\ \text{with} \space \space \text{count}(1) = 2, \space \text{count}(2) = 3
$

**Solution (using dynamic programming)**

```cpp
// C++ program to count all distinct binary strings
// without two consecutive 1's
#include <iostream>
using namespace std;

int countStrings(int n)
{
    int a[n], b[n];
    a[0] = b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
    return (a[n-1] + b[n-1])%1000000007;
}


// Driver program to test above functions
int main()
{
    cout << countStrings(3) << endl;
    return 0;
}   
```

**Solution (simplified)**
```cpp
// C++ program to count all distinct binary strings
// without two consecutive 1's
#include <bits/stdc++.h>
using namespace std;

int countStrings(int n)
{
    int a = 1, b = 1;
    for (int i = 1; i < n; i++) {
        // Here we have used the temp variable because we
        // want to assign the older value of a to b
        int temp = a + b;
        b = a;
        a = temp;
    }
    return (a + b)%1000000007;
}

// Driver program to test above functions
int main()
{
    cout << countStrings(3) << endl;
    return 0;
}
```