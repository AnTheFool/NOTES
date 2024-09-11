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