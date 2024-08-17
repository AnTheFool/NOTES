#include <bits/stdc++.h>
#define ll long long
using namespace std;

int gcd(int a, int b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main(){
    int n; cin >> n;
    int a[100001], pref[100001], suff[100001];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    pref[1] = a[1]; suff[n] = a[n];
    for (int i = 2; i <= n; i++)
        pref[i] = gcd(pref[i - 1], a[i]);
    for (int i = n - 1; i >= 1; i--)
        suff[i] = gcd(suff[i + 1], a[i]);
    int res = 0;
    for (int i = 1; i <= n; i++){
        res = max(res, gcd(pref[i - 1], suff[i + 1]));
    }
    cout << res;
    return 0;
}