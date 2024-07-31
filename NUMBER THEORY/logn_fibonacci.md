# log(n) IMPLEMENTAION

## Idea: Use addition rule

$$
F_{m + n} = F_m \times F_{n + 1} + F_{m - 1} \times F_n \\ 
\text{If } m = n: F_{2n} = F_n(F_{n + 1} + F_{n - 1}) = F_n(2F_{n + 1} - F_n) \\ 
\text{If } m = n + 1: F_{2n + 1} = F_{n + 1}^2 + F_n ^2
$$

## Implementation

```cpp
int f[1000];

// Returns n'th fibonacci number using
// table f[]
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

    int k = (n & 1) == 1? (n + 1) / 2
                        : n / 2;

    // Applying above formula [Note value
    // n&1 is 1 if n is odd, else 0.
    f[n] = (n & 1) == 1? (fib(k) * fib(k) +
                    fib(k - 1) * fib(k - 1))
                : (2 * fib(k - 1) + fib(k))
                * fib(k);

    return f[n];
}
```