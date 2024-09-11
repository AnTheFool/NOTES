# **FIBONACCI MODULO**

Given two number $N$ and $M$. The task is to find the $N$-th fibonacci number mod $M$. In general let $F_N$ be the $N$-th fibonacci number then the output should be $F_N \% M$.

```cpp
// C++ program to calculate Fibbonaci Mod M 

#include <bits/stdc++.h>
using namespace std;

class GFG{
    public:
        // Function to Calculate Pisano Period
        long pisano(long m)
        {
            long prev = 0;
            long curr = 1;
            long res = 0;
        
            for(int i = 0; i < m * m; i++)
            {
                long temp = 0;
                temp = curr;
                curr = (prev + curr) % m;
                prev = temp;
        
                if (prev == 0 && curr == 1)
                    res = i + 1;
            }
            return res;
        }
        
        // Function to Calculate Fibbonaci Mod M 
        long fibonacciModulo(long n, long m)
        {
            // Getting the period
            long pisanoPeriod = pisano(m);
            n = n % pisanoPeriod;   
            long prev = 0;
            long curr = 1;
            if (n == 0)
                return 0;
            else if (n == 1)
                return 1;
            for(int i = 0; i < n - 1; i++)
            {
                long temp = 0;
                temp = curr;
                curr = (prev + curr) % m;
                prev = temp;
            }
            return curr % m;
        }
};

// Driver Code
int main()
{
	long n = 9;
	long m = 4;
	class GFG obj;

	cout << (obj.fibonacciModulo(n, m));
	return 0;
}
```