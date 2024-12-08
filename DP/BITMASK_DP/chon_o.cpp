#include <bits/stdc++.h>
using namespace std;
#define f1(i, n) for (int i = 1; i <= n; i++)
#define f0(i, n) for (int i = 0; i < n; i++)
const unsigned int inf = 1e9 + 7;
const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
int n, a[4][maxn], f[maxn][16], d[16], ans = -3e8, res = -3e8;

bool bit(int n, int i){
    return (n >> i) & 1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f0(i, 4)    f1(j, n)    cin >> a[i][j];
    f0(i, 15){
        bool bl = 1;
        f0(j, 3)
            if (bit(i, j) && bit(i, j + 1))     bl = 0;
        d[i] = bl;
    }
    f1(i, n)    f0(mask, 16){
        if (d[mask]){
            int sum = 0;
            f0(j, 4){
                if (bit(mask, j))   sum += a[j][i];
            }
            f0(pre_mask, 16){
                if (d[pre_mask] && ((pre_mask & mask) == 0)){
                    f[i][mask] = max(f[i][mask], f[i - 1][pre_mask] + sum);
                }
            }
        }
    }
    f0(i, 16)
        if (d[i])
            ans = max(ans, f[n][i]);
    cout << ans;
    return 0;
}