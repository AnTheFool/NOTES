# **MODULAR ARITHMETIC**

## **PROPERTIES**

### Addition

$$
(a + b) \% M = \left(\left(a \% M\right) + \left(b \% M\right)\right)\% M
$$

Example:

$$
(15 + 17) \% 7 = \left(\left(15 \% 7\right) + \left(17 \% 7\right)\right)\% 7 \\ = (1 + 3) \% 7 = 4
$$

### Multiplication

$$
(a \times b) \% M = \left(\left(a \% M\right) \times \left(b \% M\right)\right)\% M
$$

$$
(15 \times 17) \% 7 = \left(\left(15 \% 7\right) \times \left(17 \% 7\right)\right)\% 7 \\ = (1 \times 3) \% 7 = 3
$$

### Factorial using mod 10^9 + 7
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--){
	    long long n, m; cin >> n >> m;
        if (n > m)
            cout << 0 << "\n";
        else{
            long long fac = 1;
    	    for (long long i = 1; i <= n; i++){
    	        fac = ((fac % m) * (i % m)) % m;
    	    }
    	    cout << fac << "\n";
        }
	}
	return 0;
}
```

### Subtraction

$$
res = (a - b) \% MOD \equiv (a \% MOD - b \% MOD) \% MOD \\ 
\text{If } res < 0: res = (res + MOD) \% MOD
$$

In other words

$$
res = ((a - b) \% MOD + MOD) \% MOD
$$

### Division

The modular division is totally different from modular addition, subtraction and multiplication. It also does not exist always.

$$
(a / b) \text{ mod } M = (a \times (\text{inverse of b if exists})) \text{ mod } M
$$