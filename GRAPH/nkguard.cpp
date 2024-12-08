#include <bits/stdc++.h>
using namespace std;
#define f1(i, n) for (int i = 1; i <= n; i++)
#define f0(i, n) for (int i = 0; i < n; i++)
const unsigned int inf = 1e9 + 7;
const unsigned int mod = 1e9 + 7;
const int maxn = 705;
int n, m, a[maxn][maxn], dd[maxn][maxn], ok, ans;
int x[] = {0, 0, -1, 1, 1, -1, 1, -1};
int y[] = {1, -1, 0, 0, 1, 1, -1, -1};

void dfs(int u, int v){
    dd[u][v] = 1;
    f0(i, 8){
        int uu = u + x[i], vv = v + y[i];
        if (a[uu][vv] == a[u][v] && dd[uu][vv] == 0) 
            dfs(uu, vv);
        if (a[uu][vv] > a[u][v])
            ok = 0;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    f1(i, n)    f1(j, m){
        cin >> a[i][j];
        a[i][j]++;
    }
    f1(i, n)    f1(j, m){
        if (dd[i][j] == 0){
            ok = 1;
            dfs(i, j);
            ans += ok;
        }
    }
    cout << ans;
    return 0;
}