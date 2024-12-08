#include <bits/stdc++.h>
using namespace std;
#define maxn 1003
#define f1(i, n) for (int i = 1; i <= n; i++)
int n, m, a[maxn][maxn], x, y, visited[maxn][maxn], cnt;

void dfs(int u, int v){
    visited[u][v] = 1;
    cnt++;
    if (u > 1 && visited[u - 1][v] == 0 && a[u - 1][v] == 1)    dfs(u - 1, v);
    if (u < n && visited[u + 1][v] == 0 && a[u + 1][v] == 1)    dfs(u + 1, v);
    if (v > 1 && visited[u][v - 1] == 0 && a[u][v - 1] == 1)    dfs(u, v - 1);
    if (v < m && visited[u][v + 1] == 0 && a[u][v + 1] == 1)    dfs(u, v + 1);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> x >> y;
    f1(i, n)    f1(j, m)    cin >> a[i][j];
    if (a[x][y] == 1)
        dfs(x, y);
    cout << cnt;
    return 0;
}