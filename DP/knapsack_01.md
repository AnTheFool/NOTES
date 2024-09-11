# **0 - 1 KNAPSACK**

We are given $N$ items where each item has some weight and profit associated with it. We are also given a bag with capacity $W$, (i.e., the bag can hold at most W weight in it). The target is to put the items into the bag such that the sum of profits associated with them is the maximum possible.

**Note:** The constraint here is we can either put an item completely into the bag or cannot put it at all (It is not possible to put a part of an item into the bag).

Example:

```
Input: N = 3, W = 4, profit[] = {1, 2, 3}, weight[] = {4, 5, 1}
Output: 3
Explanation: There are two items which have weight less than or equal to 4. If we select the item with weight 4, the possible profit is 1. And if we select the item with weight 1, the possible profit is 3. So the maximum possible profit is 3. Note that we cannot put both the items with weight 4 and 1 together as the capacity of the bag is 4.

Input: N = 3, W = 3, profit[] = {1, 2, 3}, weight[] = {4, 5, 6}
Output: 0
```

# RECURSIVE SOLUTION

A simple solution is to consider all subsets of items and calculate the total weight and profit of all subsets. Consider the only subsets whose total weight is smaller than W. From all such subsets, pick the subset with maximum profit.

**Optimal Substructure:** To consider all subsets of items, there can be two cases for every item. 

- Case 1: The item is included in the optimal subset.
- Case 2: The item is not included in the optimal set.

The maximum value obtained from ‘N’ items is the max of the following two values. 

- Maximum value obtained by N-1 items and W weight (excluding nth item)
- Value of nth item plus maximum value obtained by N-1 items and (W – weight of the Nth item) [including Nth item].
- If the weight of the ‘Nth‘ item is greater than ‘W’, then the Nth item cannot be included and Case 1 is the only possibility.

# **DP SOLUTION**

- First, create a 2D array $dp[n + 1][w + 1]$ of size $(n + 1) \times (W + 1)$, with $dp[i][j]$ being maximum value that we can collect with first $i$ items and knapsack capacity $j$.

- Base case: $dp[0][i] = 0$ and $dp[i][0] = 0$. And final result will be $dp[n][W]$

- The state $dp[i][j]$ will denote the maximum value of $j-weight$ considering all values from $1$ to $i^{th}$. So if we consider $w_i$ (weight in $i^{th}$ row) we can fill it in all columns which have weight values > $w_i$. Now two possibilities can take place: 
    - Fill $w_i$ in the given column.
    - Do not fill $w_i$ in the given column.

- Now we have to take a maximum of these two possibilities, 
    - Formally if we do not fill the $i^{th}$ weight in the $j^{th}$ column then the $dp[i][j]$ state will be the same as $dp[i-1][j]$
    - But if we fill the weight, DP[i][j] will be equal to the value of ($w_i$ + value of the column weighing $j-w_i$) in the previous row. 
- So we take the maximum of these two possibilities to fill the current state. 

```cpp
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n){
	int i, w;
	vector<vector<int> > K(n + 1, vector<int>(W + 1));

	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1]
								+ K[i - 1][w - wt[i - 1]],
							K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
}

int main(){
	int profit[] = { 60, 100, 120 };
	int weight[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(profit) / sizeof(profit[0]);

	cout << knapSack(W, weight, profit, n);

	return 0;
}
```

### **Time complexity:** $O(n \times W)$