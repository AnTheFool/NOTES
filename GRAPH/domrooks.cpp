#include <bits/stdc++.h>
using namespace std;
#define f1(i, n) for (int i = 1; i <= n; i++)
#define f0(i, n) for (int i = 0; i < n; i++)
const unsigned int inf = 1e9 + 7;
const unsigned int mod = 1e9 + 7;
const int maxn = 2e5 + 3;
int n;
pair<int, int> a[maxn];
vector<int> ax[maxn];
vector<int> ay[maxn];
int cnt, tplt, d[maxn];

void dfs(int u){
    d[u] = 1;
    for (int v : ax[a[u].first])    if (d[v] == 0)  dfs(v);
    for (int v : ay[a[u].second])   if (d[v] == 0)  dfs(v);
}

long long pow(int n){
    if (n == 0)
        return 1;
    long long t = pow(n / 2);
    t = t * t % mod;
    if (n % 2)
        t = (t * 2) % mod;
    return t;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f1(i, n){
        cin >> a[i].first >> a[i].second;
        ax[a[i].first].push_back(i);
        ay[a[i].second].push_back(i);
    }
    f1(i, 2e5){
        if (ax[i].size() == 1){
            if (d[ax[i][0]] == 0)   dfs(ax[i][0]);
        }
        if (ay[i].size() == 1){
            if (d[ay[i][0]] == 0)   dfs(ay[i][0]);
        }
    }
    f1(i, n){
        if (d[i] == 0){
            cnt++; dfs(i);
        }
    }
    cout << pow(cnt);
    return 0;
}