#include <bits/stdc++.h>
using namespace std;

int findTrailingZeros(int n){
    if (n < 0)
        return -1;
    int count = 0;
    // Keep dividing n by powers of 5 and update count
    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;
    return count;
}

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        cout << findTrailingZeros(n) << "\n";
    }
    return 0;
}