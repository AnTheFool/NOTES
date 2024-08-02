#include <bits/stdc++.h>
#define fin freopen("bcount.in", "r", stdin)
#define fout freopen("bcount.out", "w", stdout)
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    fin; fout;
    int n, q, a[100001]; cin >> n >> q;
    int holstein[100001], guernseys[100001], jerseys[100001];
    holstein[0] = 0; guernseys[0] = 0; jerseys[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] == 1){
            holstein[i] = holstein[i - 1] + 1;
            guernseys[i] = guernseys[i - 1];
            jerseys[i] = jerseys[i - 1];
        }
        else if (a[i] == 2){
            holstein[i] = holstein[i - 1];
            guernseys[i] = guernseys[i - 1] + 1;
            jerseys[i] = jerseys[i - 1];
        }
        else{
            holstein[i] = holstein[i - 1];
            guernseys[i] = guernseys[i - 1];
            jerseys[i] = jerseys[i - 1] + 1;
        }
    }
    while (q--){
        int l, r; cin >> l >> r;
        cout << holstein[r] - holstein[l - 1] << " " << guernseys[r] - guernseys[l - 1] << " " << jerseys[r] - jerseys[l - 1] << "\n";
    }
    return 0;
}