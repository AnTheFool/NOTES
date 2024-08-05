# **ACTIVITY SELECTION**

You are given $n$ activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time. 

### For example
```
Input: {(2, 3), (1, 4), (5, 8), (6, 10)}
Output: 2
Explanation: We pick {0, 2}, {1, 2}, {0, 3} or {1, 3}
```

```
Input: {(1, 3), (2, 4), (5, 8), (6, 10)}
Output: 3
Explanation: We pick {0, 1, 3}
```

## Idea and solution: 

1. Sort according to finish time:
```
{(1, 3), (2, 4), (3, 8), (10, 11)}
```

2. Initialize solution at first activity

3. Do following for remaining activities

    a. If current actiivity overlaps with the last picked activity in the solution, ignore the current activity

    b. Else add the current activity to the solution.   

### **Implementation**

```cpp
#include <iostream>
#include <cmath>
#include <bits/stdc++.h> 
#include <climits>
using namespace std;

bool myCmp(pair <int, int> a, pair <int, int> b)
{
	return (a.second < b.second);
}

int maxActivities(pair <int, int> arr[], int n)
{
	sort(arr, arr + n, myCmp);

	int prev = 0;
	int res = 1;

	for(int curr = 1; curr < n; curr++)
	{
	 
		if(arr[curr].first >= arr[prev].second)
		{
			res++;

			prev = curr;
		}
	}

	return res;
}
int main()
{
	pair <int, int> arr[] = {make_pair(12, 25), make_pair(10, 20), make_pair(20, 30)};

	int n = 3;

	cout<<maxActivities(arr, n); 

	return 0;
}
```