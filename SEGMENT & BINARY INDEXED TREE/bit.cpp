#include <bits/stdc++.h>
using namespace std;
#define maxn 200005
int bit[maxn], n, q, a[maxn];

int get(int x){
    int s = 0;
    while (x > 0){
        s += bit[x];
        x -= (x & -x);
    }
    return s;
}

void update(int x, int val){
    while (x <= n){
        bit[x] += val;
        x += (x & -x);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        update(i, a[i]);
    }
    while (q--){
        int t; cin >> t;
        if (t == 1){
            int x, v; cin >> x >> v;
            update(x, v - a[x]); a[x] = v;
        }
        else{
            int x; cin >> x;
            cout << get(x) << "\n";
        }
    }
    return 0;
}