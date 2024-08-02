#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, a[100001]; cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0, sum = 0;
    for (int l = 0, r = 0; r < n; r++) {
        sum += a[r];
        while (sum > x) {
            sum -= a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
    return 0;
}