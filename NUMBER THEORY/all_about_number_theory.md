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

$\text{Trailing 0s in n!} = \text{Count of 5s in prime factors of n!} = \text{floor}(\frac{n}{5}) + \text{floor}(\frac{n}{25}) + \text{floor}(\frac{n}{125}) + \ldots$

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

$[146/3]+[48/3]+[16/3]+[5/3]+[1/3] = 70$

$\Longleftrightarrow   48  +   16  +  5  +  1  +  0   = 70$

There is 70 is maximum power of 3 prime number. 146! is divisible by 3^70 which is maximum. 

Applying Legendre’s formula for prime factor 5.

$[146/5]+[29/5]+[5/5]+[1/5] = 35$

$\Longleftrightarrow   29  +   5  +  1  +  0   = 35$

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

$
F_n = \frac{\left(\frac{1+\sqrt{5}}{2}\right)^N + \left(\frac{1-\sqrt{5}}{2}\right)^N}{2}
$

3. **Fibonacci is a complete sequence (like powers of  2)**: The Fibonacci sequence is a complete sequence in the sense that it contains every positive integer exactly once, as a sum of some of its terms. This is because every positive integer can be expressed as a sum of non-consecutive Fibonacci numbers in a unique way.

4. **Fibonacci number can be written in matrix form**: 

$ A = 
\begin{bmatrix}
1 & 1 \\ 1 & 0
\end{bmatrix}
\Longrightarrow
A^n = 
\begin{bmatrix}
F_{n + 1} & F_n \\ F_n & F_{n - 1}
\end{bmatrix}
$

5. **Cassini's identity**

$
F_{n + 1}\times{F_{n - 1}} - F_n^2 = (-1)^n
$

6. **Additional rule**

$
F_{m + n} = F_m F_{n + 1} + F_n F_{m - 1}
$

Thus,
$
A^{m+n} = A^m \times A^n
$

7. For every positive integer m, $F_{mn}$ is a multiple of $F_n$

8. Two consecutive Fibonacci numbers are always Coprime, i.e. $GCD(F_n, F_{n + 1}) = 1$

9. We have: 

$ 
\text{GCD}\left(F_m, F_n\right) = F\left(\text{GCD}\left(m, n\right)\right)
$

10. If $F_n$ is a multiple of $F_m$ then $n$ is a multiple of $m$. In other words:

$
F_n = a\times F_m \Longleftrightarrow n = a \times m
$

## ***Related problems***

- [Count binary strings with no two consecutive 1s](/NUMBER%20THEORY/count_binary_strings.md)