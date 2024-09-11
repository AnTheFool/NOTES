# **BASIC NUMBER THEORY**

## ***TRAILING ZEROS IN FACTORIAL***

We are given a number. The task is to find the Number of Trailing Zeros in the factorial of the number. The Trailing Zeros are the Zeros, which appear at the end of a number(factorial in that case)

Example:
```
Input: 5
Output: 1
// Factorial of 5 = 5*4*3*2*1 = 120, which has one trailing 0.
```

```
Input: 100
Output: 24
```

### **Naive approach**

A simple method is to first calculate the factorial of n, then count trailing 0s in the result (We can count trailing 0s by repeatedly dividing the factorial by 10 till the remainder is not 0).

But, this method can cause overflow for slightly bigger numbers as the factorial of a number is a big number. So, we prefer the Efficient Approach

### **Efficient approach**

The idea is to consider prime factors of a factorial n. A trailing zero is always produced by prime factors 2 and 5. Our task is done if we can count the number of 5s and 2s. Consider the following examples:

- n = 5: There is one 5 and 3 2s in prime factors of 5! (2 * 2 * 2 * 3 * 5). So a count of trailing 0s is 1.
- n = 11: There are two 5s and eight 2s in prime factors of 11! (28 * 34 * 52 * 7 * 11). So the count of trailing 0s is 2.

We can easily observe that the number of 2s in prime factors is always more than or equal to the number of 5s. So if we count 5s in prime factors, we are done.

Following is the summarized formula for counting trailing 0s:

$$\text{Trailing 0s in n!} = \text{Count of 5s in prime factors of n!} = \text{floor}(\frac{n}{5}) + \text{floor}(\frac{n}{25}) + \text{floor}(\frac{n}{125}) + \ldots$$

### **Implementation for efficient solution**

Read more [here](/NUMBER%20THEORY/trailiing_zeros_factorial.cpp)

## ***MAXIMUM POWER DIVIDING FACTORIAL***

Given two numbers, fact and n, find the largest power of n that divides fact! (Factorial of fact).

Example:
```
Input: fact = 5, n = 2
Output: 3
Explanation: Value of 5! is 120. The largest power of 2 that divides 120 is 8 (or 2^3)
```

```
Input: fact = 146, n = 15
Output: 35
```

The idea is based on Legendre’s formula which finds largest power of a prime number that divides fact!. We find all prime factors of n. For every prime factor we find largest power of it that divides fact!. Finally we return minimum of all found powers. 

Illustration:

`fact = 146, n = 15`

First find the prime factor of 15 that are 3  and 5 then first divide with 3 and add i.e. Applying Legendre’s formula for prime factor 3.

$$[146/3]+[48/3]+[16/3]+[5/3]+[1/3] = 70$$

$$\Longleftrightarrow   48  +   16  +  5  +  1  +  0   = 70$$

There is 70 is maximum power of 3 prime number. 146! is divisible by 3^70 which is maximum. 

Applying Legendre’s formula for prime factor 5.

$$[146/5]+[29/5]+[5/5]+[1/5] = 35$$

$$\Longleftrightarrow   29  +   5  +  1  +  0   = 35$$

There is 35 is maximum power of 5 prime number. Minimum of two powers is 35 which is our answer.

### **Implementation**

Read more [the cpp file here](/NUMBER%20THEORY/maximum_power_dividing_factorial.cpp)

# **FIBONACCI NUMBERS**

## ***Properties***

1. Two numbers, say A and B are said to be in the golden ratio if their ratio equals the ratio of the sum of two numbers to the larger number, i.e.,

> Suppose $A > B$, then
>
> If $\frac{A}{B} = \frac{A + B}{A} = \phi = 1.618 (golden ratio)$ 
>
> then these two numbers are said to be in golden ratio. 

2. Binet's formula:. It is used to find the Nth term in the Fibonacci sequence.

$$
F_n = \frac{\left(\frac{1+\sqrt{5}}{2}\right)^N + \left(\frac{1-\sqrt{5}}{2}\right)^N}{2}
$$

3. **Fibonacci is a complete sequence (like powers of  2)**: The Fibonacci sequence is a complete sequence in the sense that it contains every positive integer exactly once, as a sum of some of its terms. This is because every positive integer can be expressed as a sum of non-consecutive Fibonacci numbers in a unique way.

4. **Fibonacci number can be written in matrix form**: 

$$ A = 
\begin{bmatrix}
1 & 1 \\ 1 & 0
\end{bmatrix}
\Longrightarrow
A^n = 
\begin{bmatrix}
F_{n + 1} & F_n \\ F_n & F_{n - 1}
\end{bmatrix}
$$

5. **Cassini's identity**

$$
F_{n + 1}\times{F_{n - 1}} - F_n^2 = (-1)^n
$$

6. **Additional rule**

$$
F_{m + n} = F_m F_{n + 1} + F_n F_{m - 1}
$$

Thus,
$$
A^{m+n} = A^m \times A^n
$$

7. For every positive integer m, $F_{mn}$ is a multiple of $F_n$

8. Two consecutive Fibonacci numbers are always Coprime, i.e. $GCD(F_n, F_{n + 1}) = 1$

9. We have: 

$$
\text{GCD}\left(F_m, F_n\right) = F\left(\text{GCD}\left(m, n\right)\right)
$$

10. If $F_n$ is a multiple of $F_m$ then $n$ is a multiple of $m$. In other words:

$$
F_n = a\times F_m \Longleftrightarrow n = a \times m
$$

## ***Implementation***

### **Recursive take**

```cpp
int fibo(int n){
    if (n <= 1)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}
```

Time complexity: $O(2^n)$

### **Dynamic programming take**

```cpp
int fibo(int n){
    if (n <= 1)
        return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++){
        c = a + b; a = b; b = c;
    }
    return c;
}
```

Time complexity: $O(n)$

## ***Related problems***

- [Count binary strings with no two consecutive 1s](/NUMBER%20THEORY/count_binary_strings.md)

- [Sum of n Fibonacci numbers](/sum_fibonacci.md)

- [Squared sum of n Fibonacci numbers](/NUMBER%20THEORY/sum_square_fibonacci.md)

# **PRIME NUMBERS**

## ***Sieve Eratosthenes***

```cpp
void SieveOfEratosthenes(int n)
{
	// Create a boolean array "prime[0..n]" and initialize
	// all entries it as true. A value in prime[i] will
	// finally be false if i is Not a prime, else true.
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++) {
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true) {
			// Update all multiples of p greater than or
			// equal to the square of it numbers which are
			// multiple of p and are less than p^2 are
			// already been marked.
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
}
```

## ***Segmented sieve***

A space specifically used for these cases:

- n is very large (say 10^9)

- We have a range [low, high] as input and high is very large (say 10^9)

### Problem

Given `low` and `high`, print all prime numbers in the range `[low, high]`

For example:
```
Input: l = 2, h = 10
Output: 2 3 5 7
```

```
Input: l = 6, h = 10
Output: 7
```

Constraints: $0 \leq l, h \leq 10^9$

### Idea for segmented sieve

Take the case `l = 6, h = 10`

1. Generate all prime numbers from 0 to $\text{floor}\left(\sqrt{h}\right)$. In this case, $\text{floor}\left(\sqrt{h}\right) = 3$

--> primes[] = [2, 3]

Time complexity: $O(\sqrt{h}\log{\log{h}})$
Space complexity: $O(\sqrt{h})$

2. Create an array of size $h - l + 1$, i.e. $(10 - 6 + 1) = 5$

isPrime[] = [T, T, T, T, T] (stands for [6, 7, 8, 9, 10])

3. Mark multiples of primes[] = {2, 3} in isPrime[]

isPrime[] = [F, T, F, F, F] (stands for [6, 7, 8, 9, 10])

Time complexity: $O((h - l + 1)\log{h})$

Overall, this algorithm takes $h\log{\log{h}}$ time and $\theta{(h)}$

### Implementation

```cpp
// C++ implementation of segmented sieve
#include<bits/stdc++.h>
using namespace std;
vector<long long>prime;
// function to store primes <= n
void sieve(long long n)
{
    vector<bool>isPrime(n+1,true);
    for(long long i=2;i<=n;i++)
    {
        if(isPrime[i])
        {
            prime.push_back(i);
            for(long long j=i*i;j<=n;j++)
            isPrime[j]=false;
        }
    }
}
// function to find primes in range [l...h] using sieve and optimizations
void segSieve(long long l, long long h)
{
    long long sq=sqrt(h);
    sieve(sq);
    vector<bool>isPrime(h-l+1,true);
    for(long long p:prime)
    {
        long long sm=(l/p)*p; // Find the smallest multiple of p greater than l
        if(sm<l)
        sm+=p;
        for(long long m=sm;m<=h;m+=p)
        isPrime[m-l]=false;
    }
    for(long long i=l;i<=h;i++)
    {
        if(isPrime[i-l]==true)
        cout<<i<<" ";
    }
}
// Driver function
int main() {
	long long l=5,h=9;
	segSieve(l,h);
	return 0;
}
```

# **MATHEMATICAL PRINCIPLES**

## ***DERANGEMENTS***

A Derangement is a permutation of n elements, such that no element appears in its original position. For example, a derangement of {0, 1, 2, 3} is {2, 3, 1, 0}.

Given a number n, find the total number of Derangements of a set of n elements.

### **Examples:**
```
Input: n = 2
Output: 1
For two elements say {0, 1}, there is only one possible derangement {1, 0}

Input: n = 3
Output: 2
For three elements say {0, 1, 2}, there are two possible derangements {2, 0, 1} and {1, 2, 0}

Input: n = 4
Output: 9
For four elements say {0, 1, 2, 3}, there are 9 possible derangements {1, 0, 3, 2}, {1, 2, 3, 0} {1, 3, 0, 2}, {2, 3, 0, 1}, {2, 0, 3, 1}, {2, 3, 1, 0}, {3, 0, 1, 2}, {3, 2, 0, 1} and {3, 2, 1, 0}
```

### Derangement recursive formula

$$
\text{dCount}(n) = (n - 1)\left(\text{dCount}(n - 2) + \text{dCount}(n - 1)\right) \\ \text{with} \space \space \text{dCount}(1) = 0, \space \space \text{dCount}(2) = 1
$$

### Implementation

```cpp
#include <iostream>
using namespace std;
 
int countDer(int n)
{
 
    // base case
    if (n == 1 or n == 2) {
        return n - 1;
    }
 
    // Variable for just storing
    // previous values
    int a = 0;
    int b = 1;
 
    // using above recursive formula
    for (int i = 3; i <= n; ++i) {
        int cur = (i - 1) * (a + b);
        a = b;
        b = cur;
    }
 
    // Return result for n
    return b;
}
 
// Driver Code
int main()
{
 
    cout << "Count of Derangements is " << countDer(4);
    return 0;
}
```

# **GCD VS LCM**

## ***Extended Euclidean Algorithm***

$$
ax + by = \gcd{(a, b)}
$$

Theo định lý Bezout, luôn luôn tồn tại cặp số nguyên $x, y$ thỏa mãn phương trình trên.

Ví dụ: 
$$
a = 12, b = 15 \Longrightarrow \gcd{(12, 15)} = 3 \\
\Longrightarrow 12x + 15y = 3 \\ 
\Longrightarrow x = -1,\space y = 1
$$

