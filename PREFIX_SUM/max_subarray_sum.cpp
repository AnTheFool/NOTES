#include <bits/stdc++.h>
#define ll long long
#define nhap cin >> n; for (int i = 1; i <= n; i++){ cin >> a[i]; }
using namespace std;
int n, a[200001]; ll pref[200001];

void prefix_sum(int n, int a[]){
    pref[0] = 0;
    for (int i = 1; i <= n; i++){
        pref[i] = pref[i-1] + a[i];
    }
}

int main(){
    nhap;
    prefix_sum(n, a);
    ll max_subarray_sum = pref[1], min_prefix_sum = pref[0];
    for (int i = 1; i <= n; i++){
        max_subarray_sum = max(max_subarray_sum, pref[i] - min_prefix_sum);
        min_prefix_sum = min(min_prefix_sum, pref[i]);
    }
    cout << max_subarray_sum << "\n";
    return 0;
}