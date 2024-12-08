#include <bits/stdc++.h>
using namespace std;
#define f1(i, n) for (int i = 1; i <= n; i++)
#define f0(i, n) for (int i = 0; i < n; i++)
const unsigned int inf = 1e9 + 7;
const unsigned int mod = 1e9 + 7;
const int maxn = 1e6 + 7;
string s;
int n, q;
struct node{
    int open, close, ans;
    static node base(){
        return {0, 0, 0};
    }
    static node add(const node &a, const node &b){
        int nn = min(a.open, b.close);
        int ans = a.ans + b.ans + nn * 2;
        int open = a.open + b.open - nn;
        int close = a.close + b.close - nn;
        node res = {open, close, ans};
        return res;
    }
} t[maxn * 4];

void build(int id, int l, int r){
    if (l == r){
        t[id] = node::base();
        if (s[l] == '(')
            t[id].open = 1;
        else 
            t[id].close = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid); build(id * 2 + 1, mid + 1, r);
    t[id] = node::add(t[id * 2], t[id * 2 + 1]);
}

node get(int id, int l, int r, int u, int v){
    if (l > v || r < u)
        return node::base();
    if (l >= u && r <= v)
        return t[id];
    int mid = (l + r) >> 1;
    return node::add(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s >> n;
    int len = s.length(); s = ' ' + s;
    build(1, 1, len);
    while (n--){
        int l, r; cin >> l >> r;
        node ans = get(1, 1, len, l, r);
        cout << ans.ans << "\n";
    }
    return 0;
}