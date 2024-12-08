#include <bits/stdc++.h>
using namespace std;
#define duyet(n) for (int i = 1; i <= n; i++)
const unsigned int maxn = 5e4 + 7;
const int inf = 1e9 + 7;

struct node{
    int pref, suff, sum, maxsum;
    static node base() {
        return { -inf, -inf, 0, -inf};
    }
    static node merge(const node &a, const node &b){
        node res;
        res.pref = max(a.pref, b.pref + a.sum);
        res.suff = max(b.suff, a.suff + b.sum);
        res.sum = a.sum + b.sum;
        res.maxsum = max({a.maxsum, b.maxsum, a.suff + b.pref});
        return res;
    }
};

int n, q, a[maxn];
node it[4 * maxn];

void build(int id, int l, int r){
    if (l == r){
        it[id] = {a[l], a[l], a[l], a[l]};
        return;        
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    it[id] = node::merge(it[id * 2], it[id * 2 + 1]);
}

node get(int id, int l, int r, int u, int v){
    if (l > v || r < u)
        return node::base();
    if (l >= u && r <= v)
        return it[id];
    int mid = (l + r) / 2;
    node g1 = get(id * 2, l, mid, u, v);
    node g2 = get(id * 2 + 1, mid + 1, r, u, v);
    return node::merge(g1, g2);
}

main(){
    cin >> n;
    duyet(n)    cin >> a[i];
    build(1, 1, n);
    cin >> q;
    while (q--){
        int x, y; cin >> x >> y;
        cout << get(1, 1, n, x, y).maxsum << "\n";
    }
    return 0;
}