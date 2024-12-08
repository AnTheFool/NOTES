#include <bits/stdc++.h>
#define maxn 100007
using namespace std;
int n, m, a[1003][1003], s, visited[1003];

void dfs(int u){
    visited[u] = 1;
    cout << u << " ";
    for (int v = 1; v <= n; v++){
        if (a[u][v] && !(visited[v]))
            dfs(v);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        a[u][v] = 1;
    }
    dfs(s);
    return 0;
}