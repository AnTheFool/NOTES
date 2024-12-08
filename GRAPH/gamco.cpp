#include <bits/stdc++.h>
using namespace std;
#define f1(i, n) for (int i = 1; i <= n; i++)
#define f0(i, n) for (int i = 0; i < n; i++)
const unsigned int inf = 1e9 + 7;
const unsigned int mod = 1e9 + 7;
const int maxn = 1e2 + 7;
int n, m, d[maxn][maxn], u, v, top;
int a[] = {0, 0, 1, -1};
int b[] = {1, -1, 0, 0};
char c[maxn][maxn];

void bfs(int u, int v){
    queue<pair<int, int>> q;
    q.push(make_pair(u, v));
    while (!q.empty()){
        pair<int, int> t = q.front();
        q.pop();
        f0(i, 4){
            int x = t.first + a[i], y = t.second + b[i];
            if (!d[x][y] && c[x][y] == '.'){
                d[x][y] = d[t.first][t.second] + 1;
                q.push(make_pair(x, y));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    f1(i, n) f1(j, m){
        cin >> c[i][j];
        if (c[i][j] == 'C'){
            u = i; v = j;
        }
    }
    c[1][1] = '.';
    d[u][v] = 1;
    bfs(u, v);
    cout << d[1][1] - 1;
    return 0;
}