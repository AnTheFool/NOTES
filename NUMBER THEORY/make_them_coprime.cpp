#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000001

int main() {
    vector<int> pf(MAXN, -1);
    pf[1] = 1;
    for (int i = 2; i < MAXN; i++){
        if (pf[i] == -1){
            for (int j = i; j < MAXN; j += i){
                if (pf[j] == -1)
                    pf[j] = i;
            }
        }
    }
	int t; cin >> t;
	while (t--){
        int ans = 0;
        int a, b; cin >> a >> b;
        while (__gcd(a, b) != 1){
            ans++;
            if (a > b)
                a /= pf[a];
            else 
                b /= pf[b];
        }
        cout << ans << "\n";
	}
	return 0;
}