#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a, b, c, d; cin >> a >> b;
    cin >> c >> d;
    vector<bool> marked(101, 0);
    for (int i = a; i < b; i++)
        marked[i] = 1;
    for (int i = c; i < d; i++)
        marked[i] = 1;
    int total = 0;
    for (auto i: marked)
        total += i;
    cout << total;
    return 0;
}