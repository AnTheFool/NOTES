#include <bits/stdc++.h>
using namespace std;
#define maxn 10004
int n, d[maxn];

void dfs(int u){
    d[u] = 1;
    for (int x = 1; x * x <= u; x++){
        if (u % x == 0){
            int y = u / x;
            if (!d[(x - 1) * (y + 1)])
                dfs((x - 1) * (y + 1));
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    dfs(n);
    vector<int> ans;
    for (int i = 0; i < n; i++){
        if (d[i])
            ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x << " ";
}