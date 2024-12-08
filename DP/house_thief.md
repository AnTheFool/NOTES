# HOUSE THIEF

There are N houses built in a line, each of which contains some value in it. A thief is going to steal the maximum value of these houses, but he can’t steal in two adjacent houses because the owner of the stolen houses will tell his two neighbors left and right sides. The task is to find what is the maximum stolen value.

Examples: 
```
Input: hval[] = {6, 7, 1, 3, 8, 2, 4}
Output: 19
Explanation: The thief will steal 6, 1, 8 and 4 from the house.

Input: hval[] = {5, 3, 4, 11, 2}
Output: 16
Explanation: Thief will steal 5 and 11
```

# RECURSION SOLUTION

We can start from the last house and for each house, we have two choices:

1. Rob the current house and skip the house just before it.
2. Skip the current house and move to the next house.

So, the recursive relation can be:

```
maxLootRec(n) = max(hval[n - 1] + maxLootRec(n - 2), maxLootRec(n - 1))
```

where `maxLootRec(n)` returns the maximum amount of money which can be stolen if n houses are left.

## ***Code implementation***

```cpp
#include <iostream>
using namespace std;

int maxLoot(int* hval, int n){
	if (n < 0) {
		return 0;
	}

	if (n == 0) {
		return hval[0];
	}
	int pick = hval[n] + maxLoot(hval, n - 2);
	int notPick = maxLoot(hval, n - 1);
	return max(pick, notPick);
}

int main(){
	int hval[] = { 6, 7, 1, 3, 8, 2, 4 };
	int n = sizeof(hval) / sizeof(hval[0]);
	cout << "Maximum loot possible : "
		<< maxLoot(hval, n - 1);
	return 0;
}
```

# DP SOLUTION

The idea is to build the solution in bottom-up manner. We create a dp[] array of size n+1 where dp[i] represents the maximum value that can be collected with first i houses. We first fill the known values, dp[0] and dp[1] and then fill the remaining values using the formula: dp[i] = max(hval[i] + dp[i – 2], dp[i – 1]). The final result will be stored at dp[n].

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the maximum stolen value using bottom-up DP
int maxLoot(vector<int>& hval) {
    int n = hval.size();
  
    // Create a dp array to store the maximum loot at each house
    vector<int> dp(n+1, 0);

    // Base cases
    dp[0] = 0;
    dp[1] = hval[0];

    // Fill the dp array using the bottom-up approach
    for (int i = 2; i <= n; i++) 
        dp[i] = max(hval[i - 1] + dp[i - 2], dp[i - 1]);

    return dp[n];
}

int main() {
    vector<int> hval = {6, 7, 1, 3, 8, 2, 4};
    cout << maxLoot(hval) << endl;
    return 0;
}
```