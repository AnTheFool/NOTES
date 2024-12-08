#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int s, bool visited[]){
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty()){
        int u = q.front(); q.pop();
        for (int v : adj[u]){
            if (visited[v] == false){
                visited[v] = true;
                q.push(v);                
            }
        }
    }
}

int tplt(vector<int> adj[], int v){
    bool visited[v];
    int count = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= v; i++){
        if (visited[i] == false){
            bfs(adj, i, visited);
            count++;
        }
    }
    return count;
}

int main(){
    int v, e; cin >> v >> e;
    vector<int> adj[100000];
    for (int i = 1; i <= e; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << tplt(adj, v) << endl;
    return 0;
}