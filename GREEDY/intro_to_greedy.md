# **GREEDY**

## **INTRO TO GREEDY ALGORITHM**

Greedy is an algorithmic paradigm that builds up a solution piece by piece, always choosing the next piece that offers the most obvious and immediate benefit. So the problems where choosing locally optimal also leads to the global optimal solution are best fit for Greedy.

Consider this problem

Consider infinite supply of the following value coins: 10, 5, 2, 1. If someone asks for an amount, how will you give this amount using minimum coins?

For example:
```
Amount = 52
Take 5 coins of 10 and 1 coin of 2.
```

### **Solution**

```cpp
#include <bits/stdc++.h> 
using namespace std;

int minCoins(int coin[], int n, int amount)
{	
    sort(coin, coin + n);
    int res = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(coin[i] <= amount)
        {
            int c = floor(amount / coin[i]);
            res = res + c;
            amount = amount - c * coin[i];
        }
        if(amount == 0)
            break;
    }
    return res;
}
    
int main() {
    int coin[] = {5, 10, 2, 1}, n = 4, amount = 57;
    cout<<minCoins(coin, n, amount); 
}
```

### **General structure of greedy algorithm**

`getoptimal(item arr[], int n)`

```
1. Initialize res = 0
2. While (all items are not considered){
    i = select_an_item()

    if (feasible(i))
        
        res = res + i
}

3. Return res
```

### **Notes**

Greedy algorithms may not always work, especially for finding the longest path.

### **Applications**

1. Finding optimal solutions:

- Activity selection

- Fractional knapsack

- Job sequencing

- Prim's algorithm

- Kruskal's algorithm

- Djikstra's algorithm

- Huffman coding

2. Finding close to optimal solution for NP Hard Problems like Travelling Salesman Problem.

## RELATED PROBLEMS

- [Activity problems](/GREEDY/activity_problems.md). View solutions [here](/GREEDY/activity_problems.cpp)