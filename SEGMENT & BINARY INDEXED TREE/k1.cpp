#include <bits/stdc++.h>
using namespace std;
#define f1(i, n) for (int i = 1; i <= n; i++)
#define f0(i, n) for (int i = 0; i < n; i++)
const unsigned int inf = 1e9 + 7;
const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
int n, q, a[maxn], ft[maxn];

void update(int x, int val){
    for (;x <= maxn; x += (x & -x))
        ft[x] += val;
}

int get(int x){
    int res = 0;
    for (; x; x -= (x & -x))
        res += ft[x];
    return res;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    f1(i, n)    cin >> a[i];
    while (q--){
        int type, x; cin >> type >> x;  
        if (type == 1){
            if (a[x] == 0)
                a[x] = 1, update(x, 1);
            else
                a[x] = 0, update(x, -1);
        }
        else{
            int idx = 0, total = 0;
            for (int i = 31; i >= 0; i--){
                int next_idx = idx + (1 << i);
                if (next_idx <= n && total + ft[next_idx] < x){
                    idx = next_idx;
                    total += ft[next_idx];
                }
            }
            cout << idx + 1 << "\n";
        }
    }
    return 0;
}