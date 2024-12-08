#include <bits/stdc++.h>
using namespace std;
const int maxn = 10001;
const int mod = 5e7;
#define ll long long
#define f1(i, n) for (int i = 1; i <= n; i++)
int n, k, a[maxn];
vector<int> b;
ll t[52][maxn], ans, f[52][maxn];

void up(int x, int i, int v){
    for (;x < maxn; x += (x & -x))
        t[i][x] = (t[i][x] + v) % mod;
}

ll get(int x, int i){
    ll s = 0;
    for (;x; x -= (x & -x))
        s = (s + t[i][x]) % mod;
    return s;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    f1(i, n){
        cin >> a[i];
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    f1(i, n){
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
    }
    f1(i, n){
        f1(j, k){
            if (j == 1){
                f[1][i] = 1;
                up(a[i], j, 1);
            }
            else{
                f[j][i] = get(a[i] - 1, j - 1);
                up(a[i], j, f[j][i]);
            }
        }
    }
    f1(i, n)
        ans = (ans = f[k][i]) % mod;
    cout << ans;
    return 0;
}