#include <bits/stdc++.h>
using namespace std;
#define f1(i, n) for (int i = 1; i <= n; i++)
#define f0(i, n) for (int i = 0; i < n; i++)
#define ll long long
const unsigned int inf = 1e9 + 7;
const unsigned int mod = 1e9 + 7;
const int maxn = 1e6 + 3;
int n, q, a[maxn], d, mi[maxn * 4];
ll s[maxn * 4];

int get_min(int id, int l, int r, int u, int v){
    if (l > v || r < u)
        return 0;
    if (l >= u && r <= v)
        return mi[id];
    int m = (l + r) / 2;
    int p1 = get_min(id * 2, l, m, u, v), p2 = get_min(id * 2 + 1, m + 1, r, u, v);
    if (a[p1] <= a[p2])
        return p1;
    else
        return p2;
}

ll get_sum(int id, int l, int r, int u, int v){
    if (l > v || r < u)
        return 0;
    if (l >= u && r <= v)
        return s[id];
    int m = (l + r) / 2;
    return get_sum(id * 2, l, m, u, v) + get_sum(id * 2 + 1, m + 1, r, u, v);
}

void update(int id, int l, int r, int pos, int val){
    if (pos < l || pos > r)
        return;
    if (l == r){
        a[pos] = val;
        s[id] = val;
        mi[id] = l;
        return;
    }
    int m = (l + r) >> 1;
    update(id * 2, l, m, pos, val); update(id * 2 + 1, m + 1, r, pos, val);
    if (a[mi[id * 2]] <= a[mi[id * 2 + 1]])
        mi[id] = mi[id * 2];
    else
        mi[id] = mi[id * 2 + 1];
    s[id] = s[id * 2] + s[id * 2 + 1];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    a[0] = 1e9;
    f1(i, n){
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }
    while (q--){
        int t; cin >> t;
        if (t == 1){
            int dd; cin >> dd;
            d += dd;
            if (d > n)
                d %= n;
        }
        if (t == 2){
            int l, r, v; cin >> l >> r >> v;
            l -= d; r -= d;
            if (l <= 0) l += n;
            if (r <= 0) r += n;
            if (l <= r){
                int p = get_min(1, 1, n, l, r);
                update(1, 1, n, p, v);
            }
            else{
                int p1 = get_min(1, 1, n, l, n);
                int p2 = get_min(1, 1, n, 1, r);
                if (a[p1] <= a[p2])
                    update(1, 1, n, p1, v);
                else
                    update(1, 1, n, p2, v);
            }
        }
        if (t == 3){
            int l, r; cin >> l >> r;
            l -= d; r -= d;
            if (l <= 0) l += n;
            if (r <= 0) r += n;
            if (l <= r)
                cout << get_sum(1, 1, n, l, r);
            else
                cout << get_sum(1, 1, n, l, n) + get_sum(1, 1, n, 1, r);
            cout << "\n";
        }
    }
    return 0;
}