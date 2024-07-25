#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll area(ll n){
    ll dt = 0;
    for (ll i = 2; i <= n; i *= 2)
        dt += n / i;
    return dt;
}

int main(){
    ll lf, rt; cin >> lf >> rt;
    cout << area(rt) - area(lf - 1);
    return 0;
}