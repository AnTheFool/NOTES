#include <bits/stdc++.h>
using namespace std;
int n, m, a[1003][1003];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1; // Add vào khi đây là đồ thị vô hướng
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}