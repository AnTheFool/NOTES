#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    vector<int> pref(10001, 0);
    while (t--){
        int n; cin >> n;
        string s; cin >> s;
        for (int i = 0; i < s.length(); i++){
            pref[i + 1] = pref[i] + (s[i] - '0');
        }
        int count = 0, l = 1, r = 1;
        while (r <= n && l <= r){
            int sum = pref[r] - pref[l - 1], length = r - l + 1;
            if (sum == length)
                count++;
            else if (sum > length)
                l++;
            else
                r++;
        }
        cout << count << "\n";
    }
    return 0;
}