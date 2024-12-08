#include <bits/stdc++.h>
using namespace std;
#define f1(i, n) for (int i = 1; i <= n; i++)
#define f0(i, n) for (int i = 0; i < n; i++)
const unsigned int inf = 1e9 + 7;
const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
int n, m, d[maxn];
vector<int> adj[maxn];

void dfs(int u){
    for (auto v : adj[u]){
        d[v] = d[u] + 1; dfs(v);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    f1(i, m){
        int p, u, v; cin >> p >> u >> v;
        adj[p].push_back(u);
        adj[p].push_back(v);
    }
    d[1] = 1;
    dfs(1);
    f1(i, n)
        cout << d[i] << "\n";
    return 0;
}