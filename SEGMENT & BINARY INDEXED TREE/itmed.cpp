#include <bits/stdc++.h>
using namespace std;
#define maxn 100007
#define ll long long
int n, k; ll a[maxn], it[maxn * 4];

void update(int id, int l, int r, int pos){
    if (pos < l || pos > r)
        return;
    if (l == r)
        return void(it[id] = a[pos]);
    int m = (l + r) >> 1;
    update(id * 2, l, m, pos); update(id * 2 + 1, m + 1, r, pos);
    it[id] = max(it[id * 2], it[id * 2 + 1]);
}

ll get(int id, int l, int r, int u, int v){
    if (l > v || r < u)
        return -1e18;
    if (l >= u && r <= v)
        return it[id];
    int m = (l + r) >> 1;
    return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)    cin >> a[i];
    update(1, 1, n, 1);
    for (int i = 2; i <= n; i++){
        a[i] += max(get(1, 1, n, max(i - k, 1), i - 1), 0LL); 
        update(1, 1, n, i);
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, a[i]);
    cout << res;
    return 0;
}