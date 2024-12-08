#include <bits/stdc++.h>
using namespace std;
#define f1(i, n) for (int i = 1; i <= n; i++)
#define f0(i, n) for (int i = 0; i < n; i++)
const unsigned int inf = 1e9 + 7;
const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
int n, x, y, s, t;
vector<int> a[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x >> y >> s >> t;
    int d[maxn];
    d[s] = 1;
    queue<int> q; q.push(s);
    while (q.size()){
        int u = q.front(); 
        if (u == t)
            break;
        q.pop();
        if (u + x <= n && !d[u + x]){
            d[u + x] = d[u] + 1;
            q.push(u + x);
        }
        if (u - y > 0 && !d[u - y]){
            d[u - y] = d[u] + 1;
            q.push(u - y);
        }
    }
    cout << d[t] - 1;
    return 0;
}