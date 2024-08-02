#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
  int n; cin >> n;
  vector<int> a(n);
  vector<int> m(n); ll pref = 0;
  m[pref] = 1;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    pref += (ll)a[i];
    m[(pref % n + n) % n]++;
  }
  ll ans = 0;
  for (ll x: m){
    ans += x * (x - 1) / 2;
  }
  cout << ans;
  return 0;
}
