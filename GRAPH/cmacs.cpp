#include <bits/stdc++.h>
using namespace std;
#define f1(i, n) for (int i = 1; i <= n; i++)
#define f0(i, n) for (int i = 0; i < n; i++)
const unsigned int inf = 1e9 + 7;
const unsigned int mod = 1e9 + 7;
const int maxn = 1e3 + 7;
int n, m, ans, visited[maxn][maxn];
char a[maxn][maxn];
int x[] = {0, 0, 1, -1};
int y[] = {1, -1, 0, 0};

void dfs(int u, int v){
    if (a[u][v] == '.' || visited[u][v] || u < 1 || v < 1 || u > n || v > m)
        return;
    visited[u][v] = 1;
    f0(i, 4)
        dfs(u + x[i], v + y[i]);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    f1(i, n)    f1(j, m)    cin >> a[i][j];
    f1(i, n)    f1(j, m){
        if (a[i][j] == '*' && visited[i][j] == 0){
            dfs(i, j); ans++;
        }
    }
    cout << ans;
    return 0;
}