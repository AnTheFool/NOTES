#include <bits/stdc++.h>
using namespace std;
#define f1(i, n) for (int i = 1; i <= n; i++)
#define f0(i, n) for (int i = 0; i < n; i++)
const unsigned int inf = 1e9 + 7;
const unsigned int mod = 1e9 + 7;
const int maxn = 1e6 + 7;
string s; int dp[26][maxn];
int n, q;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q; cin >> s;
    f0(i, n){
        dp[s[i] - 'a'][i + 1]++;
    }
    f0(c, 26){
        f1(i, n)
            dp[c][i] += dp[c][i - 1];
    }
    while (q--){
        int l, r, ans = 0; cin >> l >> r;
        l++; r++;
        f0(c, 26){
            if ((dp[c][r] - dp[c][l - 1]) % 2 != 0)
                ans++;
        }
        cout << ans / 2 << "\n";
    }
    return 0;
}