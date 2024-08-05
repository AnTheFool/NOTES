# COUNT SET BITS

Write an efficient program to count the number of 1s in the binary representation of an integer.

### ***Example:***

```
Input: 5
Output: 2
Explanation: Binary representation of 5 is 101 and has 2 set bits

Input: 7
Output: 3
Explanation: Binary representation of 7 is 111 and has 2 set bits
```

## **Naive solution**

Simple method: Loop through all bits in an integer, check if a bit is set and if it is, then increment the set bit count.

```cpp
// C++ program to Count set 
// bits in an integer 
#include <bits/stdc++.h> 
using namespace std; 

/* Function to get no of set bits in binary 
representation of positive integer n */
unsigned int countSetBits(unsigned int n) 
{ 
	unsigned int count = 0; 
	while (n != 0) {
	    if (n % 2 != 0)
	       count++;
	    n = n/2;      
	} 
	return count; 
} 

/* Program to test function countSetBits */
int main() 
{ 
	int i = 9; 
	cout << countSetBits(i); 
	return 0; 
} 

```

Time complexity: $O(\log{n})$

Auxiliary space: $\theta{(1)}$

## **Brian Kerningan's Algorithm**

Time complexity: $O(\text{set bit count})$

### How this work

Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) including the rightmost set bit. for example : 

10 in binary is 00001010 

9 in binary is 00001001 

8 in binary is 00001000 

7 in binary is 00000111 

So if we subtract a number by 1 and do it bitwise & with itself `(n & (n-1))`, we unset the rightmost set bit. If we do `n & (n-1)` in a loop and count the number of times the loop executes, we get the set bit count. 
The beauty of this solution is the number of times it loops is equal to the number of set bits in a given integer.

1. Initialize count: = 0
2. If integer n is not zero
- (a) Do bitwise & with (n-1) and assign the value back to n

        n: = n&(n-1)

- (b) Increment count by 1
- (c) go to step 2
3. Else return count

```cpp
// C++ program to Count set
// bits in an integer
#include <iostream>
using namespace std;
class gfg {
	/* Function to get no of set bits in binary
representation of passed binary no. */
public:
	unsigned int countSetBits(int n)
	{
		unsigned int count = 0;
		while (n) {
			n &= (n - 1);
			count++;
		}
		return count;
	}
};
/* Program to test function countSetBits */
int main()
{
	gfg g;
	int i = 9;
	cout << g.countSetBits(i);
	return 0;
}
```

## Lookup table:

We can count bits in O(1) time using the lookup table.

Initially, we will create a table size 256 to store the count of set bits of each number from 1 to 256.
```cpp
int table[256];
void initialize(){
    table[0] = 0;
    for (int i = 1; i < n; i++)
        table[i] = (i & 1) + table[i / 2];
}
```

Then, count the set bits
```cpp
int count(int n){
    int res = table[n & 0xff];
    n = n >> 8;
    res += table[n & 0xff];
    n = n >> 8;
    res += table[n & 0xff];
    n = n >> 8;
    res += table[n & 0xff];
    return res;
}
```