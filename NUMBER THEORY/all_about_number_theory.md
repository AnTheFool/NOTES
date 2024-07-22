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