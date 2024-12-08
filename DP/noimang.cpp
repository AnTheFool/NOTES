#include <bits/stdc++.h>
using namespace std;
#define f1(i, n) for (int i = 1; i <= n; i++)
#define f0(i, n) for (int i = 0; i < n; i++)
const unsigned int inf = 1e9 + 7;
const unsigned int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, f[maxn], a[maxn];
    cin >> n;
    for (int i = 1; i < n; i++)
        cin >> a[i];
    f[2] = a[1]; f[3] = a[1] + a[2];
    for (int i = 4; i <= n; i++)
        f[i] = min(f[i - 1] + a[i - 1], f[i - 2] + a[i - 1]);
    cout << f[n];
    return 0;   
}