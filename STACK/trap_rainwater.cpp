#include <bits/stdc++.h>
using namespace std;

int maxwater(int height[], int n){
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++){
        while ((!st.empty()) && (height[st.top()] < height[i])){
            int pop_height = height[st.top()];
            st.pop();
            if (st.empty())
                break;
            int distance = i - st.top() - 1;
            int min_height = min(height[st.top()], height[i]) - pop_height;
            ans += distance * min_height;
        }
        st.push(i);
    }
    return ans;
}

int main(){
    int n, a[100000]; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << maxwater(a, n);
    return 0;
}