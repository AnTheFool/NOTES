#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll u, v; cin >> u >> v;
    ll sq = u * u + v * v;
    if (sq % 4 == 0)
        cout << sq / 4 << ".00";
    else if (sq % 4 == 1)
        cout << sq / 4 << ".25";
    else if (sq % 4 == 2)
        cout << sq / 4 << ".50";
    else
        cout << sq / 4 << "/75";
    return 0;
}