#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, a[100000]; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int leftsum = 0, sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    for (int i = 0; i < n; i++){
        int rightsum = sum - a[n - i - 1];
        if (leftsum == rightsum)
            cout << i << endl;
            return 0;
        leftsum += a[i];
    }
}