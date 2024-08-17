# **MEMOIZATION DP (TOP DOWN)**

If we need to find the value for some state say `dp[n]` and instead of starting from the base state that i.e `dp[0]` we ask our answer from the states that can reach the destination state `dp[n]` following the state transition relation, then it is the top-down fashion of DP. 

Here, we start our journey from the top most destination state and compute its answer by taking in count the values of states that can reach the destination state, till we reach the bottom-most base state. 

Example: I will study the theory of DP from GeeksforGeeks, then I will practice some problems on classic DP and hence I will master DP.

Let's see the implementation of this top-down approach to calculate Fibonacci number

```cpp
#include <iostream>
#include <string.h>
using namespace std;

int memo[1000000];

int fib(int n)
{
    if(memo[n]==-1){
        int res;
        if (n==0 || n==1)
            return n;
        else
            res = fib(n-1)+fib(n-2);
        memo[n]=res;
    }
    return memo[n];
}

int main() {
	int n = 5;
	memset(memo, -1, sizeof(memo));
	cout<<fib(5);
}
```

# **TABULATION DP (BOTTOM UP)**

As the name itself suggests starting from the bottom and accumulating answers to the top. Let's discuss in terms of state transition. 

Let's describe a state for our DP problem to be `dp[x]` with `dp[0]` as base state and `dp[n]` as our destination state. So,  we need to find the value of destination state i.e `dp[n]`. 

If we start our transition from our base state i.e `dp[0]` and follow our state transition relation to reach our destination state `dp[n]`, we call it the Bottom-Up approach as it is quite clear that we started our transition from the bottom base state and reached the topmost desired state. 

**Now, Why do we call it the tabulation method?**

To know this let's first write some code to calculate the factorial of a number using a bottom-up approach. Once, again as our general procedure to solve a DP we first define a state. In this case, we define a state as `dp[x]`, where `dp[x]` is to find the factorial of `x`. 

Now, it is quite obvious that `dp[x+1] = dp[x] * (x+1)`.

```cpp
// Tabulated version to find factorial x.
int dp[MAXN];

// base case
int dp[0] = 1;
for (int i = 1; i< =n; i++)
{
    dp[i] = dp[i-1] * i;
}
```

Here's another example of top-down approach to calculate Fibonacci numbers:

```cpp
#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    int f[n + 1];
    f[0] = 0;  f[1] = 1;
    for(int i = 2;i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    return f[n];
}

int main() {
	int n = 5;
	cout<<fib(n);
}
```

# RELATED PROBLEMS

## [LONGEST COMMON SUBSEQUENCE](/DP/lcs.md)

## [LONGEST INCREASING SEQUENCE](/DP/LIS.md)