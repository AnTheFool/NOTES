#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
int n, q, a[maxn], f[maxn][21], g[maxn][21];

int get_min(int l, int r){
    int k = log2(r - l + 1);
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}

int get_max(int l, int r){
    int k = log2(r - l + 1);
    return max(g[l][k], g[r - (1 << k) + 1][k]);
}

int main(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        f[i][0] = a[i]; g[i][0] = a[i];
    }
    for (int l = 1; (1 << l) <= n; l++){
        for (int i = 1; i + (1 << l) - 1 <= n; i++){
            f[i][l] = min(f[i][l - 1], f[i + (1 << (l - 1))][l - 1]);
            g[i][l] = max(g[i][l - 1], g[i + (1 << (l - 1))][l - 1]);
        }
    }
    while (q--){
        int l, r; cin >> l >> r;
        if (l == r)
            cout << "YES\n";
        if (get_max(l, r) == get_min(l, r))
            cout << "NO\n";
        
    }
    return 0;
}