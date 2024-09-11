Given an array `a` of `n` integers (`n` will be odd), you can do the following operation on array: Choose any index and increment the value at it (i.e. choose any index i and do `a[i] = a[i] + 1`). Cost of each operation is 1 rupee. What is the maximum median you can get using at most `k` rupees?

**Constraints**

$$
1\leq n\leq 10^5 \\
1\leq a[i], k\leq 5\cdot10^8
$$

**Example:**

```
n = 3, k = 2
a[] = [1, 3, 5]
Output: 5 
Explanation: 
- Choose i = 1, then a[] = [1, 4, 5]
- Choose i = 1 again, then a[] = [1, 5, 5]
--> Final answer = median = 5

n = 3, k = 4
a[] = [1, 5, 3]
Output: 6
```

**Solution**

```cpp
#include <bits/stdc++.h>
using namespace std;

int cost(int m, int n, int a[]) {
	int req = 0; for (int i = n / 2; i < n; i++) {
		req += max(0, m - a[i]);
	}
	return req;
}

int maximumMedian(int n, int k, int a[]) {
	sort(a, a + n);
	int lo = a[n / 2], hi = a[n / 2] + k;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (cost(mid, n, a) <= k) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	return lo;
}

int main()
{
	int n = 7, k = 8;
	int arr[] = {4, 1, 5, 6, 1, 7, 6};
	cout << maximumMedian(n, k, arr);
	return 0;
}
```