#include <bits/stdc++.h>
using namespace std;
#define f1(i, n) for (int i = 1; i <= n; i++)
#define f0(i, n) for (int i = 0; i < n; i++)
const unsigned int inf = 1e9 + 7;
const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
int n, m, k, vis[maxn];
vector<int> adj[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    queue<int> q;
    f1(i, k){
        int x; cin >> x;
        q.push(x);
        vis[x] = 1;
    }
    cin >> m;
    f1(i, m){
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    while (q.size()){
        int u = q.front(); q.pop();
        for (int v : adj[u]){
            if (!vis[v]){
                vis[v] = vis[u] + 1; q.push(v);
            }
        }
    }
    f1(i, n)
        cout << vis[i] - 1 << " ";
    return 0;
}