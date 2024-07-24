#include <bits/stdc++.h>
using namespace std;
int sieve[100001];

void sieve_prime(){
    memset(sieve, 1, sizeof(sieve));
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i <= 100000; i++){
        if(sieve[i]){
            for(int j = i*2; j <= 100000; j += i){
                sieve[j] = 0;
            }
        }
    }
}

int main(){
    sieve_prime(); 
    int t; cin >> t;
    while (t--){
        int n, a[1000]; string s; cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cin >> s;
        string check = "";
        for (int i = 0; i < n; i++){
            if (sieve[a[i]]){
                check += '1';
            } else {
                check += '0';
            }
        }
        if (check == s){
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}