#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    stack<pair<int, int>> st;
    st.push({a[0], 1});
    cout << 0 << " ";
    for (int i = 1; i < n; i++) {
        while (!st.empty() && st.top().first >= a[i]) 
            st.pop();
        if (st.empty()) 
            cout << 0 << " ";
        else 
            cout << st.top().second << " ";
        st.push({a[i], i + 1});
    }
    return 0;
}