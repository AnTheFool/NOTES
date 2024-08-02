#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;
        int i = 0;
        while (s[i] != s[s.length() - i - 1] && i < s.length() / 2)
            i++;
        cout << s.length() - (2 * i) << "\n";
    }
    return 0;
}