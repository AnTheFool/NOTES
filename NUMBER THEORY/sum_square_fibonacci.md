# SUM OF SQUARE FIBONACCI NUMBERS

## Naive solution

```cpp
int sumSquaresFib(int n)
{
    if(n<=1)
        return n;
    int a = 0, b = 1, sum=1;
    for (int i = 2; i <= n; i++)
    {
        int c = a + b;
        a = b;
        b = c;
        sum += c*c;
    }
    return sum;
}
```

## Efficient solution

Based on the formula

$$
\sum^{n}_{i = 0}{F_i^2} = F_n\times F_{n + 1}
$$

```cpp
const int MAX = 1000;
 
// Create an array for memoization
int f[MAX] = { 0 };
 
// Returns n'th Fibonacci number using table f[]
int fib(int n)
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);
 
    // If fib(n) is already computed
    if (f[n])
        return f[n];
 
    int k = (n & 1) ? (n + 1) / 2 : n / 2;
 
    // Applying above formula [Note value n&1 is 1
    // if n is odd, else 0].
    f[n] = (n & 1) ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1))
                   : (2 * fib(k - 1) + fib(k)) * fib(k);
 
    return f[n];
}
 
// Function to calculate sum of
// squares of Fibonacci numbers
int calculateSumOfSquares(int n)
{
    return fib(n) * fib(n + 1);
}
```