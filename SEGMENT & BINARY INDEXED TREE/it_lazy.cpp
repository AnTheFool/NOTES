#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 3;
const int inf = 1e9 + 7;
#define ll long long
#define for(a, b, c) for(int a = b; a <= c; a++)
int n, q; ll a[maxn], it[4 * maxn], lazy[4 * maxn];

void up(int id){
    for(i, id * 2, id * 2 + 1){
        it[i] += lazy[id];
        lazy[i] += lazy[id];
    }
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val){
    if (l > v || r < u)
        return;
    if (l >= u && r <= v){
        lazy[id] += val;
        it[id] += val;
        return;
    }
    up(id);
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, val); update(id * 2 + 1, mid + 1, r, u, v, val);
    it[id] = max(it[id * 2], it[id * 2 + 1]);
}

ll get(int id, int l, int r, int u, int v){
    if (l > v || r < u)
        return -inf;
    if (l >= u && r <= v)
        return it[id];
    up(id);
    int mid = (l + r) / 2;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(i, 1, n){
        cin >> a[i];
        update(1, 1, n, i, i, a[i]);
    }
    cin >> q;
    while (q--){
        int type; cin >> type;
        if (type == 1){
            int x, y, val; cin >> x >> y >> val;
            update(1, 1, n, x, y, val);
        }
        else{
            int l, r; cin >> l >> r;
            cout << get(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}