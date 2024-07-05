#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int n, int arr[]){
    vector<int> res;
    int maximum = arr[n - 1];
    res.push_back(maximum);
    for (int i = n - 2; i >= 0; i--){
        if (arr[i] >= maximum){
            maximum = arr[i];
            res.push_back(arr[i]);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio();
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        vector<int> res = leaders(n, arr);
        for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";
        cout << endl;
    }
}