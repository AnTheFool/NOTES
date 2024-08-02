#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a[1000], s = 0, d = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = n - 1, turn = 1;
    while (l <= r){
        if (turn % 2 != 0){
            if (a[l] < a[r]){
                s += a[r]; r--;
            }
            else{
                s += a[l]; l++;
            }
        }
        else{
            if (a[l] < a[r]){
                d += a[r]; r--;
            }
            else{
                d += a[l]; l++;
            }
        }
        turn++;
    }
    cout << s << " " << d;
    return 0;
}