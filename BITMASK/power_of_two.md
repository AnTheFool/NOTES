# POWER OF TWO

Check if number `n` is a power of two

For example:

```
Input: n = 4
Output: true

Input: n = 6
Output: false
```

## Method 1: Naive

```cpp
#include <iostream>
using namespace std;

bool isPow2(int n)
{
    if(n == 0)
        return true;
    
    while(n != 1)
    {
        if(n % 2 != 0)
            return false;
        
        n = n / 2;
    }
    
    return true;
}
    
int main() {
	
	int n = 4;
	
	printf("%s", isPow2(n)? "true": "false");
}
```

## Method 2: Efficient solution

Using Brian Kerningan's algorithm

```cpp
#include <iostream>
using namespace std;

bool isPow2(int n)
{
    if(n == 0)
        return true;
    
    return ((n & (n - 1)) == 0);
}
    
int main() {
	
	int n = 4;
	
	printf("%s", isPow2(n)? "true": "false");
}
```