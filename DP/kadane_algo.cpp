#include <bits/stdc++.h>
using namespace std;

long long maximumSum(long long arr[], int sizeOfArray)
{
    long long dp[sizeOfArray];
    dp[0] = arr[0];
    long long ans = dp[0];
    for (int i = 1; i < sizeOfArray; i++){
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        ans = max(dp[i], ans);
    }
    return ans;
}

int main(){
    int n; cin >> n;
    long long arr[100000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maximumSum(arr, n);
    return 0;
}