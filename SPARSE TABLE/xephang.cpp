#include <bits/stdc++.h>
#define maxn 50004
using namespace std;
int n, q, a[maxn], f[21][maxn], g[21][maxn];

int get_min(int l, int r){
    int k = log2(r - l + 1);
    return min(f[k][l], f[k][r - (1 << k) + 1]);
}

int get_max(int l, int r){
    int k = log2(r - l + 1);
    return max(g[k][l], g[k][r - (1 << k) + 1]);
}

int main(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        f[0][i] = a[i];
        g[0][i] = a[i];
    }
    for (int l = 1; (1 << l) <= n; l++){
        for (int i = 1; i + (1 << l) - 1 <= n; i++){
            f[l][i] = min(f[l - 1][i], f[l - 1][i + (1 << (l - 1))]);
            g[l][i] = max(g[l - 1][i], g[l - 1][i + (1 << (l - 1))]);
        }
    }
    while (q--){
        int l, r; cin >> l >> r;
        cout << get_max(l, r) - get_min(l, r) << "\n";
    }
    return 0;
}