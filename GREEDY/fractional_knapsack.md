# **FRACTIONAL KNAPSACK**

## Problem statement

Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.

Note: you are allowed to break the item.

### Example: 
```
Input: 
N = 3
W = 50
K = [10, 20, 30]
V = [60, 100, 120]
Output:
240
Explanation:
60 + 100 + (2/3) * 120 = 240
```

## Idea and solution:

1. Sort by profit ratio, in which profit ratio = value / weight

2. Add weight to the `total_weight`, if `total_weight` smaller than `max_weight` then add value to `total_value`, until `total_weight` bigger than `max_weight`, then add fractional of `curr_value` to `total_value` and end the process
3. Return `total_value` as the result.

### Implementation

View [here](/GREEDY/fractional_knapsack.cpp)