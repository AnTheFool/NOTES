#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

int main(){
  ll a, b; cin >> a >> b;
  cout << gcd(a, b);
  return 0;
}