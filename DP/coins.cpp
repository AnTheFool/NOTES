#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<long double> p(n + 1); long double dp[3001][3001];
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    int least_heads = n / 2 + 1;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= least_heads; j++){
            dp[i][j] = dp[i - 1][j - 1] * p[i] + dp[i - 1][j] * (1 - p[i]);
        }
    }
    cout << setprecision(10) << dp[n][least_heads];
    return 0;
}

