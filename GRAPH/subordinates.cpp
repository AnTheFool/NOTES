#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> tree[200001];

void solve(int source, int parent, vector<int> &ans){
    int subords = 0;
    for (int child : tree[source]){
        if (child != parent){
            solve(child, source, ans);
            subords += (1 + ans[child]);
        }
    }
    ans[source] = subords;
}

int main(){
    int n; cin >> n;
    vector<int> ans(n + 1);
    for (int i = 2; i <= n; i++){
        ll x; cin >> x;
        tree[x].push_back(i);
        tree[i].push_back(x);
    }
    solve(1, 0, ans);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}