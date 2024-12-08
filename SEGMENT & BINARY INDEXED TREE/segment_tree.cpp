#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
int n, node[4 * maxn], q, a[maxn];

void build(int id, int l, int r){
    if (l == r){
        node[id] = a[l]; return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    node[id] = max(node[id * 2], node[id * 2 + 1]);
}

int get_max(int id, int l, int r, int u, int v){
    if (r < u || l > v)
        return -1e9;
    if (u <= l && r <= v)
        return node[id];
    int mid = (l + r) / 2;
    int max_l = get_max(id * 2, l, mid, u, v);
    int max_r = get_max(id * 2 + 1, mid + 1, r, u, v);
    return max(max_l, max_r);
}

void update(int id, int l, int r, int pos, int val){
    if (pos < l || pos > r)
        return;
    if (l == r){
        a[l] = val;
        node[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    node[id] = max(node[2 * id], node[2 * id + 1]);
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    cin >> q;
    while (q--){
        int type, x, y; cin >> type >> x >> y;
        if (type == 1)
            update(1, 1, n, x, y);
        else
            cout << get_max(1, 1, n, x, y) << "\n";
    }
    return 0;
}