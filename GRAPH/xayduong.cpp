#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
int n, m, visited[maxn];
vector<int> adj[maxn];

void dfs(int u){
    visited[u] = 1;
    for (int v : adj[u]){
        if (!visited[v])
            dfs(v);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cnt++; dfs(i);
        }
    }
    cout << cnt - 1;
    return 0;
}