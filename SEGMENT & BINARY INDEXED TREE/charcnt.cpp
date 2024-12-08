#include <bits/stdc++.h>
using namespace std;
#define f1(i, n) for (int i = 1; i <= n; i++)
#define f0(i, n) for (int i = 0; i < n; i++)
const unsigned int inf = 1e9 + 7;
const unsigned int mod = 1e9 + 7;
const int maxn = 5e5 + 7;
int n, q; string s;
int t[26][maxn];

void update(int k, int x, int v){
    for (;x < maxn; x += (x & -x))
        t[k][x] += v;
}

int get(int k, int x){
    int ans = 0;
    for (; x; x -= (x & -x))
        ans += t[k][x];
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s; s = ' ' + s;
    f1(i, n)
        update(s[i] - 'a', i, 1);
    cin >> q;
    while (q--){
        int type, x; cin >> type >> x;
        if (type == 1){
            char c; cin >> c;
            update(s[x] - 'a', x, -1);
            s[x] = c;
            update(c - 'a', x, 1);
        }
        else{
            int y, ans = 0; cin >> y;
            f0(i, 26)
                if (get(i, y) - get(i, x - 1))
                    ans++;
            cout << ans << "\n";
        }
    }
}