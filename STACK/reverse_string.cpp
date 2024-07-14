#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; getline(cin, s);
    string res = "";
    stack<int> st_index;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '(')
            st_index.push(i);
        else if (s[i] == ')'){
            int start = st_index.top();
            st_index.pop();
            reverse(s.begin() + start + 1, s.begin() + i);
        }
    }
    cout << s << endl;
}