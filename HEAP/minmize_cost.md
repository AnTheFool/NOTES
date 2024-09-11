# **MINIMIZE THE COST**

Given an array of positive Integers. In one operation you can choose (delete) any two numbers Tom the array and insert the sum of these two numbers into the array, And cost of one operation is the sum of those numbers . After several operations you are left with only one number. You are asked to tell the minimum total cost to make the array of size one.

Consider the following array:
```
arr = [3, 6, 5, 4, 9]
Output: 61
```
Explanation: 
1. Delete 3, 4 and insert 3 + 4 --> cost = 7. `arr` becomes `[7, 5, 6, 9]`
2. Delete 5, 6 and insert 5 + 6 --> cost = 7 + 11 = 18. `arr` becomes `[7, 11, 9]`
3. Delete 7, 9 and insert 7 + 9 --> cost = 18 + 16 = 34. `arr` becomes `[11, 16]`
4. Delete 11, 16 and insert 11 + 16 --> cost = 34 + 27 = 61. `arr` becomes `[27]`

## Intuition: 
Sum the two minimum elements then push back to the priority queue.

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto& it: v){
        cin >> it;
    }
    priority_queue<int, vector<int>, greater<int>>pq;
    for(auto it : v){
        pq.push(it);
    }
    int cost = 0;
    while(pq.size() > 1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        cost += (x + y);
        pq.push(x + y);
    }
    cout << "Cost = " << cost << "\n";
    return 0;
}
```