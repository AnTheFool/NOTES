#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
#define duyet(n) for (int i = 1; i <= n; i++)
#define ll long long
int n, k;
ll a[maxn], b[maxn], diff[maxn], st_gcd[maxn][50];

ll get(int l, int r){
    int k = log2(r - l + 1);
    return __gcd(st_gcd[l][k], st_gcd[r - (1 << k) + 1][k]);
}

int main(){
    cin >> n >> k;
    duyet(n)    cin >> a[i];
    duyet(n)    cin >> b[i];
    duyet(n){
        diff[i] = abs(b[i] - a[i]);
        st_gcd[i][0] = diff[i];
    }
    for (int len = 1; (1 << len) <= n; len++){
        for (int i = 1; i + (1 << len) - 1 <= n; i++){
            st_gcd[i][len] = __gcd(st_gcd[i][len - 1], st_gcd[i + (1 << (len - 1))][len - 1]);
        }
    }
    while (k--){
        int l, r; cin >> l >> r;
        cout << get(l, r) << "\n";
    }
    return 0;
}