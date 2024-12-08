#include <bits/stdc++.h>
using namespace std;
#define f1(i, n) for (int i = 1; i <= n; i++)
#define f0(i, n) for (int i = 0; i < n; i++)
const unsigned int inf = 1e9 + 7;
const unsigned int mod = 1e9 + 7;
const int maxn = 1e3 + 7;
int n, m, d[maxn][maxn];
int x[] = {1, -1};
int y[] = {2, -2};
queue<pair<int, int>> q;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    memset(d, -1, sizeof(d));
    d[x1][y1] = 0;
    q.push({x1, y1});
    while (q.size()){
        int u = q.front().first, v = q.front().second;
        if (u == x2 && v == y2)
            return cout << d[u][v], 0;
        q.pop();
        f0(i, 2)    f0(j, 2){
            int uu = u + x[i], vv = v + y[j];
            if (uu > 0 && vv > 0 && uu <= n && vv <= m && d[uu][vv] == -1){
                d[uu][vv] = d[u][v] + 1;
                q.push({uu, vv});
            }
            uu = u + y[i], vv = v + x[j];
            if (uu > 0 && vv > 0 && uu <= n && vv <= m && d[uu][vv] == -1){
                d[uu][vv] = d[u][v] + 1;
                q.push({uu, vv});
            }
        }
    }
    cout << -1;
}