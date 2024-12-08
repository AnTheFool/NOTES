#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 3;
const int inf = 1e9 + 7;
int n, q, a[maxn];

struct Node{
    int ln, count;
    static Node base() {
        return {-inf, 0};
    }
    static Node max_count(const Node &a, const Node &b){
        if (a.ln == b.ln)
            return {a.ln, a.count + b.count};
        else if (a.ln > b.ln)
            return a;
        else
            return b;
    }
} st[maxn * 4];

void build(int id, int l, int r){
    if (l == r){
        st[id] = {a[l], 1};
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid); build(id * 2 + 1, mid + 1, r);
    st[id] = Node::max_count(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int pos, int val){
    if (pos < l || pos > r)
        return;
    if (l == r){
        st[id] = {val, 1};
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val); update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = Node::max_count(st[id * 2], st[id * 2 + 1]);
}

Node get_max(int id, int l, int r, int u, int v){
    if (l > v || r < u)
        return Node::base();
    if (l >= u && r <= v)
        return st[id];
    int mid = (l + r) / 2;
    Node max_l = get_max(id * 2, l, mid, u, v);
    Node max_r = get_max(id * 2 + 1, mid + 1, r, u, v);
    return Node::max_count(max_l, max_r);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--){
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        build(1, 1, n);
        while (q--){
            int type; cin >> type;
            if (type == 1){
                int l, x; cin >> l >> x;
                update(1, 1, n, l, x);
            }
            else{
                int l, r; cin >> l >> r;
                Node max_val = get_max(1, 1, n, l, r);
                cout << max_val.count << "\n";
            }
        }
    }
    return 0;
}