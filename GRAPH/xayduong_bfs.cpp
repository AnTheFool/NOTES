#include <bits/stdc++.h>
using namespace std;
#define f1(i, n) for (int i = 1; i <= n; i++)
#define f0(i, n) for (int i = 0; i < n; i++)
const unsigned int inf = 1e9 + 7;
const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
int n, m, visited[maxn];
vector<int> a[maxn];

void bfs(int u){
    queue<int> q; q.push(u);
    while (q.size()){
        int u = q.front(); q.pop();
        for (int v : a[u]){
            if (!visited[v]){
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    f1(i, m){
        int u, v; cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
    int ans = 0;
    f1(i, n){
        if (!visited[i]){
            bfs(i);
            ans++;
        }
    }
    cout << ans;
    return 0;
}