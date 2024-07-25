#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll M = 998244353;
ll f[100000];

ll fib(ll n){
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);
    if (f[n] != 0)
        return f[n];
    ll k = (n & 1) == 1 ? (n + 1) / 2 : n / 2;
    f[n] = (n & 1) == 1 ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1)) : (2 * fib(k - 1) + fib(k)) * fib(k);

    return f[n];
}

int main(){
    ll n; cin >> n;
    if (n == 1)
        cout << 1;
    else{
        ll kq = 1;
        kq = (kq * fib(n + 2)) % M;
        kq = (kq * fib(n + 1)) % M;
        cout << kq;
    }
    return 0;
}