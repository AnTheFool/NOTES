#include <bits/stdc++.h>
using namespace std;
#define maxn 100006
int n, q, a[maxn], st[21][maxn], m;

int get(int l, int r){
    int k = log2(r - l + 1);
    return max(st[k][l], st[k][r - (1 << k) + 1]);
}

main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    while (m--){
        int u, v, k; cin >> u >> v >> k;
        a[u] += k; a[v + 1] -= k;
    }
    for (int i = 1; i <= n; i++){
        a[i] += a[i - 1];
        st[0][i] = a[i];
    }
    for (int l = 1;  (1 << l) <= n; l++){
        for (int i = 1; i + (1 << l) - 1 <= n; i++){
            st[l][i] = max(st[l - 1][i], st[l - 1][i + (1 << (l - 1))]);
        }
    }
    int q; cin >> q;
    while (q--){
        int l, r; cin >> l >> r;
        cout << get(l, r) << "\n";
    }
    return 0;
}