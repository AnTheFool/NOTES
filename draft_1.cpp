#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll pref[200001];

void prefix_sum(int n, ll a[]){
  pref[0] = 0;
  for (int i = 1; i <= n; i++)
    pref[i] = pref[i - 1] + a[i];
}

int main(){
  int n; ll a[200001]; cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  prefix_sum(n, a);
  int count = 0;
  for (int i = 1; i <= n; i++){
    for (int j = i; j <= n; j++){
      if ((pref[j] - pref[i - 1]) % n == 0)
        count++;
    }
  }
  cout << count;
  return 0;
}