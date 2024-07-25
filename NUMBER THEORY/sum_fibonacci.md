# SUM OF FIBONACCI NUMBERS FROM 0 TO N

## Naive solution

```cpp
int fib(int n)
{
    if(n<=1)
    return n;
    int a = 0, b = 1, sum=1;
    for (int i = 2; i <= n; i++)
    {
        int c = a + b;
        a = b;
        b = c;
        sum += c;
    }
    return sum;
}
```

## Efficient solution

Based on the formula:
$$
\sum{F_n} = F(n + 2) - 1
$$

```cpp
int MAX = 1000;
int f[100005];
// fib returns nth fibonacci number using table f[]
int fib(int n)
{
    // Base cases
    if (n == 0)
    return 0;
             
    if (n == 1 || n == 2)
    return (f[n] = 1);
      
    // If fib(n) is already computed
    if (f[n] != 0)
    return f[n];
      
    int k = (n & 1) == 1? (n + 1) / 2 : n / 2;
      
    // Applying above formula [Note value
    // n&1 is 1 if n is odd, else 0.
    f[n] = (n & 1) == 1? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1)): (2 * fib(k - 1) + fib(k))* fib(k);
      
    return f[n];
}
int sumFibo(int n)
{
    return fib(n+2) - 1;
}
```