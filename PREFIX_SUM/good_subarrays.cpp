#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        int n; string s; cin >> n >> s;
        ll pref[100001]; pref[0] = 0;
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + (s[i - 1] - '0') - 1;
        map<ll, ll> mp; ll ans = 0;
        for (int i = 0; i <= n; i++)
            mp[pref[i]]++;
        for (auto x : mp)
            ans += x.second * (x.second - 1) / 2;
        cout << ans << "\n";
    }    
    return 0;
}