#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj, int source){
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    queue<int> q;
    q.push(source); visited[source] = true;
    while (!q.empty()){
        int u = q.front(); q.pop();
        res.push_back(u);
        for (int v : adj[u]){
            if (!visited[v]){
                q.push(v); visited[v] = true;
            }
        }
    }
    return res;
}

vector<int> bfs_disconnect(vector<vector<int>> adj){
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    for (int i = 0; i < adj.size(); i++){
        if (!visited[i]){
            for (int it: bfs(adj, i)){
                res.push_back(it);
                visited[it] = true;
            }
        }
    }
    return res;
}

int main(){
    int v, e; cin >> v >> e;
    vector<vector<int>> adj(v);
    for (int i = 0; i < e; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> res = bfs_disconnect(adj);
    for (auto it : res)
        cout << it << " ";
    return 0;
}