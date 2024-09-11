# DIVISORS

## NUMBER WITH EXACTLY 3 DIVISORS

Cho trước một số tự nhiên $n$, hãy in ra các số tự nhiên trong khoảng $[1, n]$ sao cho số ước nguyên dương của số đó bằng 3.

Ví dụ:
```
n = 16 --> 4 9
n = 50 --> 4 9 25 49
```

### **Hướng làm**

Ta để ý rằng chỉ có số chính phương của một số nguyên tố mới có số ước nguyên dương bằng 3. 

```cpp
// C++ program to print all
// three-primes smaller than
// or equal to n without using
// extra space
#include <bits/stdc++.h>
using namespace std;

void numbersWith3Divisors(int);
bool isPrime(int);

// Generates all primes upto n and
// prints their squares
void numbersWith3Divisors(int N)
{
    cout << "Numbers with 3 divisors : " << endl;
    for (int i = 2; i * i <= N; i++) {
        // Check prime
        if (isPrime(i)) {
            if (i * i <= N) {
                // Print numbers in
                // the order of
                // occurrence
                cout << i * i << " ";
            }
        }
    }
}

// Check if a number is prime or not
bool isPrime(int N)
{
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0)
            return false;
    }
    return true;
}

// Driver code
int main()
{
    int N = 122;
    // Function call
    numbersWith3Divisors(N);
    return 0;
}
```

## COUNT FACTORS

Từ dạng tổng quát:
$$
n = p_1^{e_1}\cdot p_2^{e_2}\cdot \ldots \cdot p_k^{e_k}
$$

Ta suy ra số ước của $n$ là:

$$
(e_1 + 1)(e_2 + 1)\ldots(e_k + 1)
$$

### **How to implement**

```cpp
// C++ implementation to count all divisors
#include <iostream>
using namespace std;
// function to count the divisors
int countDivisors(int n)
{
	int res = 1;
	for (int i = 2; i*i <=n ; i++)
	{
		int cnt = 0;
	    while (n % i == 0) {
		n = n/i;
		cnt++;
		}
		res = res * (cnt+1);
	}
	if(n >= 2)
    res = res * 2;
		    
	return res;
}
/* Driver program to test above function */
int main() {
	int n=72;
	cout<<countDivisors(n)<<endl;
	return 0;
}
```

## COUNT FACTORS FOR MUILTIPLE QUERIES

Cho $t$ số tự nhiên, nhiệm vụ là tính số ước nguyên dương của từng số

Example:

```
Input: 
3
72
15
11
Output:
12
4
2
```

### **Hướng làm:**

- Đầu tiên, tạo một mảng `sieve` chứa ước nguyên tố nhỏ nhất của từng số từ $1$ đến $n$. Công đoạn này sẽ mất $O(n\log{\log{n}})$ thời gian xử lý

- Sau đó, trả lời từng query trong thời gian $O(\log{n})$ 

```cpp
// C++ program to count factors for multiple queries
#include<bits/stdc++.h>
using namespace std;
int MAX=1000000;
vector<int>least_prime(MAX+1,0);
void fillSmallestSieve()
{
    // function to calculate minimum prime factor
    for(int i=1;i<=MAX;i++)
    least_prime[i]=i;
    for(int i=2;i*i<=MAX;i++)
    {
        if(least_prime[i]==i)
        {
            for(int j=i*i;j<=MAX;j+=i)
            {
                if(least_prime[j]==j)
                least_prime[j]=i;
            }
        }
    }
}
int query(int n)
{
    int res=1, prev=least_prime[n];
    int count=1;
    n/=prev;
    while(n>1)
    {
        if(least_prime[n]==prev)
        count++;
        else
        {
            prev=least_prime[n];
            res=res*(count+1);
            count=1;
        }
        n/=prev;
    }
    res=res*(count+1);
    return res;
}
// Driver function
int main() {
    fillSmallestSieve(); // pre-processing
	int q;
	cin>>q;
	while(q--)
	{
	    int n;
	    cin>>n;
	    cout<<query(n)<<endl;
	}
	return 0;
}
```

## SUM OF DIVISORS

### **Hướng làm cho 1 query**

Nếu sử dụng cách biểu diễn:

$$
n = p_1^{e_1}\cdot p_2^{e_2}\cdot \ldots \cdot p_k^{e_k}
$$

thì tổng các ước của $n$ là:
$$
S = \sum^{e_1}_{i = 1}{p_1^i}\cdot\sum^{e_2}_{i = 1}{p_2^i}\cdot\ldots\cdot\sum^{e_k}_{i = 1}{p_k^i}
\\ = \left(\frac{p_1^{e_1 + 1} - 1}{p_1 - 1}\right)\cdot\left(\frac{p_2^{e_2 + 1} - 1}{p_2 - 1}\right)\cdot\ldots\cdot\left(\frac{p_k^{e_k + 1} - 1}{p_k - 1}\right)
$$

```cpp
int sumfactors(int n){
    int res = 1;
    for (int i = 2; i * i<= n; i++){
        int sum = 1;
        int term = 1;
        while (n % i == 0){
            n /= i;
            term *= i;
            sum += term;
        }
        res *= sum;
    }
    if (n >= 2)
        res = res * (n + 1);
    return res;
}
```

### **Hướng làm cho nhiều queries**

Ta cũng sử dụng ý tưởng tương tự:

1. Tiền xử lý trong $O(\log{\log{MAX}})$ để tìm ước nguyên tố nhỏ nhất

2. Sau đó, xử lý từng query trong $O(\log{n})$

```cpp
#include<bits/stdc++.h>
using namespace std;

#define MAXN 10001
int least_prime[MAXN] ;

void leastPrimeFactor(){
    least_prime[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        // least_prime[i] == 0
        // means it i is prime
        if (least_prime[i] == 0)
        {           
            // marking the prime number
            // as its own lpf
            least_prime[i] = i;
            // mark it as a divisor for all its
            // multiples if not already marked
            for (int j = i*i; j < MAXN; j += i)
                if (least_prime[j] == 0)
                    least_prime[j] = i;
        }
    }

}
int query(int n){
    int res=1,prev = least_prime[n];
    int term = prev,sum= 1+prev;
    n= n/prev;
    while(n>1)
    {
        if(least_prime[n]==prev)
        {
            term = term*prev;
            sum = sum+term;
        }
        else
        {
            prev = least_prime[n];
            res = res * sum;
            term = prev;
            sum = 1+ term;
        }
        n = n/prev;
    }
    res=res*sum;
    return res;
}

// Driver Code
int main(){
    leastPrimeFactor();
    int n = 72;
    cout<<query(n);
}
``` 