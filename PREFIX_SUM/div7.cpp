#include <bits/stdc++.h>
#define fin freopen("div7.in", "r", stdin)
#define fout freopen("div7.out", "w", stdout)
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fin; fout;
    int n, a[100001], div[100001], sum_div = 0; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum_div = (sum_div + a[i]) % 7;
        div[i] = sum_div;
    }
    int max_dis = 0;
    for (int i = 0; i < n; i++){
        for (int j = n - 1; j >= i; j--){
            if (div[i] == div[j]){
                max_dis = max(j - i, max_dis);
                break;
            }
        }
    }
    cout << max_dis;
    return 0;
}