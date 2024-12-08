#include <bits/stdc++.h>
using namespace std;
#define f1(i, n) for (int i = 1; i <= n; i++)
#define f0(i, n) for (int i = 0; i < n; i++)
#define ll long long
const unsigned int inf = 1e9 + 7;
const unsigned int mod = 998244353;
const int maxn = 1e5 + 7;

ll nhan_ando(ll a, ll b){
    if (b == 0)
        return 0;
    ll t = nhan_ando(a, b / 2) % mod;
    if (b & 1)
        return ((t + t) % mod + a % mod) % mod;
    else
        return (t + t) % mod;
}

void nhanmatran(ll a[4][4], ll b[4][4], ll res[4][4]){
    ll mul[4][4];
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            mul[i][j] = 0;
            for (int k = 0; k < 2; k++)
                mul[i][j] = ((mul[i][j] % mod) + nhan_ando(a[i][k], b[k][j])) % mod;
        }
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++)
            res[i][j] = mul[i][j];
    }
}

void power(ll a[4][4], ll b[4][4], ll res[4][4], ll n){
    for (; n != 0; n /= 2){
        if (n % 2 == 1)
            nhanmatran(res, a, res);
        nhanmatran(a, a, a);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll a[4][4], b[4][4];
    a[0][0] = 1; a[0][1] = 1; a[1][0] = 1; a[1][1] = 0;
    b[0][0] = 1; b[0][1] = 1; b[1][0] = 1; b[1][1] = 0;
    ll res[4][4]; res[0][0] = 1; res[0][1] = 1; res[1][0] = 1; res[1][1] = 1;

    ll n; cin >> n;
    power(a, b, res, n - 1);
    cout << res[1][1] * res[1][0];
    return 0;
}