#include <bits/stdc++.h>
#define ll long long
using namespace std;

int maxPF(int n){
    int res = -1;
    for (int i = 2; i * i <= n; i++){
        while (n % i == 0){
            res = i; n /= i;
        }
    }
    if (n > 1)
        res = n;
    return res;
}

int largest_pow(int n, int fact){
    int p = maxPF(n);
    int res = 0;
    while (fact > 0){
        fact /= p; res += fact;
    }
    return res;
}

int main(){
    int n, fact; cin >> n >> fact;
    cout << largest_pow(n, fact);
    return 0;
}