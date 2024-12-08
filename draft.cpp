#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool prime[10000001];

void sieve(){
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i = 2; i*i <= 10000000; i++){
        if(prime[i]){
            for(int j = i*i; j <= 10000000; j += i){
                prime[j] = false;
            }
        }
    }
}

int main(){
    sieve(); int n; cin >> n;
    for (int i = 2; i <= n; i++){
        if (prime[i])
            cout << i << " ";
    }
    return 0;
}