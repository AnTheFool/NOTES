#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 3;
const int inf = 1e9 + 7;
#define ll long long
int n, q, a[maxn]; ll down[4 * maxn], up[4 * maxn];

void build(ll node[], int id, int l, int r){
    if (l == r){
        node[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(node, id * 2, l, mid);
    build(node, id * 2 + 1, mid + 1, r);
    node[id] = min(node[id * 2], node[id * 2 + 1]);
}

void update(ll node[], int id, int l, int r, int pos, int val){
    if (pos < l || pos > r)
        return;
    if (l == r){
        node[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(node, id * 2, l, mid, pos, val);
    update(node, id * 2 + 1, mid + 1, r, pos, val);
    node[id] = min(node[id * 2], node[id * 2 + 1]);
}

ll get_min(ll node[], int id, int l, int r, int u, int v){
    if (r < u || l > v)
        return inf;
    if (l >= u && r <= v)
        return node[id];
    int mid = (l + r) / 2;
    return min(get_min(node, id * 2, l, mid, u, v), get_min(node, id * 2 + 1, mid + 1, r, u, v));
}

void pull(int i){
    update(down, 1, 1, n, i, a[i] - i);
    update(up, 1, 1, n, i, a[i] + i);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        pull(i);
    while (q--){
        int type; cin >> type;
        if (type == 1){
            int pos, val; cin >> pos >> val;
            a[pos] = val;
            pull(val);
        }
        else{
            int k; cin >> k;
            ll d = get_min(down, 1, 1, n, 1, k) + k;
            ll u = get_min(up, 1, 1, n, k, n) - k;
            cout << min(d, u) << "\n";
        }
    }
    return 0;
}