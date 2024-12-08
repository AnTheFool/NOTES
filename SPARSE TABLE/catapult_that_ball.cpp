#include <bits/stdc++.h>
using namespace std;
#define maxn 50004
int n, m, a[maxn], st[maxn][21];

int get(int l, int r){
    int k = log2(r - l + 1);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        st[i][0] = a[i];
    }
    for (int len = 1; (1 << len) <= n; len++){
        for (int i = 1; i + (1 << len) - 1 <= n; i++)
            st[i][len] = max(st[i][len - 1], st[i + (1 << (len - 1))][len - 1]);
    }
    int ans = 0;
    while (m--){
        int l, r; cin >> l >> r;
        if (abs(l - r) < 2){
            ans++;
            continue;
        }
        int x = a[l];
        if (l > r)
            swap(l, r);
        if (x >= get(l + 1, r - 1))
            ans++;
    }
    cout << ans;
    return 0;
}