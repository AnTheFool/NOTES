#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n]; // Mảng tĩnh
    vector<int> stat; // Mảng động
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> stat[i];
    // Linked list
    string s;
    // Stack 
    stack<int> st;
    // Queue
    queue<int> q;
    // Deque
    deque<int> dq;
    // Binary tree, BST (Binary search tree), map, pair, tuple, priority queue
    // Disjoint set
    // Graph --> BFS, DFS, Djikstra
    // Greedy, DP
    // Bitmask, Modulo, Catalan, v.v...
    // Recursion --> Backtracking
    // Divide and conquer (quicksort), Heap, Fenwick tree
}