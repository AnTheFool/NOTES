#include <bits/stdc++.h>
using namespace std;
#define maxn 60004
#define ll long long
int n, q, a[maxn], t[maxn], bit[maxn];
ll ans;

int get(int x){
    int s = 0;
    for (; x < maxn; x += (x & -x)){
        s += bit[x];
    }
    return s;
}

void update(int x, int val){
    for (; x; x -= (x & -x))
        bit[x] += val;
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        ans += get(a[i] + 1);
        update(a[i], 1);
    }
    cout << ans;
    return 0;
}