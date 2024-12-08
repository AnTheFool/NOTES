#include <bits/stdc++.h>
using namespace std;
#define f1(i, n) for (int i = 1; i <= n; i++)
#define f0(i, n) for (int i = 0; i < n; i++)
const unsigned int inf = 1e9 + 7;
const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
int n, q, a[maxn], t[maxn * 4];

int add(int i, int j){
    return (a[i] > a[j]) ? i : j;
}

void build(int id, int l, int r){
    if (l == r){
        t[id] = l;
        return;
    }
    int m = (l + r) >> 1;
    build(id * 2, l, m); build(id * 2 + 1, m + 1, r);
    t[id] = add(t[id * 2], t[id * 2 + 1]);
}

void update(int id, int l, int r, int pos){
    if (pos < l || pos > r)
        return;
    if (l == r){
        t[id] = pos;
        return;
    }
    int m = (l + r) >> 1;
    update(id * 2, l, m, pos); update(id * 2 + 1, m + 1, r, pos);
    t[id] = add(t[id * 2], t[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v){
    if (r < u || l > v)
        return 0;
    if (l >= u && r <= v)
        return t[id];
    int m = (l + r) >> 1;
    return add(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

long long mul(long long a, long long b, long long mod){
    if (b == 0)
        return 0;
    long long t = mul(a, b / 2, mod) * 2;
    if (b % 2)
        t += a;
    return t % mod;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> q;
    build(1, 1, n);
    while (q--){
        int type; cin >> type;
        if (type == 0){
            int x, v; cin >> x >> v;
            a[x] = v;
            update(1, 1, n, x);
        }
        else{
            int l, r; long long modul;
            cin >> l >> r >> modul;
            int p1 = get(1, 1, n, l, r);
            int p2 = add(get(1, 1, n, l, p1 - 1), get(1, 1, n, p1 + 1, r));
            cout << mul(a[p1], a[p2], modul) << "\n";

        }
    }
    return 0;
}