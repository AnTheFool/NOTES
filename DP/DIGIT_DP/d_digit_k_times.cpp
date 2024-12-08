#include <bits/stdc++.h>
using namespace std;

int l, r, d, k; 
vector<int> num;
int dp[10][2][10];

int go(int i, bool flag, int count){
    if (i == num.size())
        return (count == k);
    if (dp[i][flag][count] != -1)
        return dp[i][flag][count];
    int ans = 0;
    if (flag){
        for (int digit = 0; digit <= 9; digit++){
            ans += go(i + 1, true, count + (digit == d));
        }
    }
    else{
        for (int digit = 0; digit <= num[i]; digit++){
            if (digit < num[i])
                ans += go(i + 1, true, count + (digit == d));
            else
                ans += go(i + 1, false, count + (digit == d));
        }
    }
    dp[i][flag][count] = ans;
    return ans;
}

int f(int x){
    num.clear();
    while (x > 0){
        num.push_back(x % 10);
        x /= 10;
    }
    reverse(num.begin(), num.end());
    memset(dp, -1, sizeof(dp));
    return go(0, false, 0);
}

int main(){
    cin >> l >> r >> d >> k;
    cout << f(r) - f(l - 1) << endl;
    return 0;
}