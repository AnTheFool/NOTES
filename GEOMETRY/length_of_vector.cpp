#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define x first
#define y second

int main(){
    pii a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    cout << round(sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
    return 0;
}