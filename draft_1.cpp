#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t; cin >> s >> t;
    int n = s.length();
    map<char, int> dict_s, dict_t;
    int ans = 0, track = 0;
    for (int i = 0; i < n; i++){
        dict_s[s[i]]++;
        dict_t[t[i]]++;
        if (dict_s.size() == dict_t.size() && equal(dict_s.begin(), dict_s.end(), dict_t.begin())){
            ans++;
            dict_s.clear();
            dict_t.clear();
        }
    }
    cout << ans;
    return 0;
}