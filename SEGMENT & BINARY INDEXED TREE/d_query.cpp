#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4 + 5;
const int inf = 1e9 + 7;
int n, q, a[maxn]; set<int> node[maxn * 4];

void build(int id, int l, int r){
    if (l == r){
        node[id].insert(a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid); build(id * 2 + 1, mid + 1, r);
    node[id].insert(node[id * 2].begin(), node[id * 2].end());
    node[id].insert(node[id * 2 + 1].begin(), node[id * 2 + 1].end());
}

set<int> get(int id, int l, int r, int u, int v){
    if (l > v || r < u)
        return {};
    if (l >= u && r <= v)
        return node[id];
    int mid = (l + r) >> 1;
    set<int> left = get(id * 2, l, mid, u, v);
    set<int> right = get(id * 2 + 1, mid + 1, r, u, v);
    set<int> res = left;
    res.insert(right.begin(), right.end());
    return res;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];    
    build(1, 1, n);
    cin >> q;
    while (q--){
        int l, r; cin >> l >> r;
        set<int> res = get(1, 1, n, l, r);
        cout << res.size() << "\n";
    }
    return 0;
}