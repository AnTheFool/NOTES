#include <bits/stdc++.h>
using namespace std;

int suffix[100001];

void suffix_array(int n, int arr[]){
    suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suffix[i] = min(suffix[i + 1], arr[i]);
}

void solve(int n, int arr[]){
    int ans[n]; 
    memset(ans, -1, sizeof(ans));
    for (int i = n - 2; i >= 0; i--){
        int l = i + 1, r = n - 1;
        while (l <= r){
            int m = l + (r - l) / 2;
            if (suffix[m] < arr[i]){
                ans[i] = m; l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int arr[100001];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        suffix_array(n, arr); 
        solve(n, arr);
        cout << "\n";
    }
    return 0;
}