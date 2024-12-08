#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 3;
int n, m, a[maxn], r[maxn], it[maxn * 4];

void build(int id, int l, int r){
    if (l == r){
        it[id] = a[l];
    }
    else{    
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        it[id] = max(it[id * 2], it[id * 2 + 1]);
    }
}

void update(int id, int l, int r, int x){
    if (l == r){
        it[id] -= x;
        cout << l << " ";
    }
    else{    
        int mid = (l + r) / 2;
        if (it[id * 2] >= x)
            update(id * 2, l, mid, x);
        else
            update(id * 2 + 1, mid + 1, r, x);
        it[id] = max(it[id * 2], it[id * 2 + 1]);
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while (m--){
        int x; cin >> x;
        if (it[1] < x)
            cout << "0 ";
        else    
            update(1, 1, n, x);
    }
    return 0;
}