#include <bits/stdc++.h>
using namespace std;

int l, r; vector<int> num; int dp[10][2][10][10];

int go(int i, bool flag, int fd, int ld){
    if (i == num.size())
        return (fd == ld);
    int &mem = dp[i][flag][fd][ld];
    if (mem != -1)
        return mem;
    int ans = 0;
    if (flag){
        for (int digit = 0; digit <= 9; digit++){
            int new_fd = fd;
            if (fd == 0)
                new_fd = digit;
            int new_ld = digit;
            ans += go(i + 1, true, new_fd, new_ld);
        }
    }
    else{
        for (int digit = 0; digit <= num[i]; digit++){
            int new_fd = fd;
            if (fd == 0)
                new_fd = digit;
            int new_ld = digit;
            if (digit < num[i])
                ans += go(i + 1, true, new_fd, new_ld);
            else
                ans += go(i + 1, false, new_fd, new_ld);
        }
    }
    mem = ans;
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
    return go(0, false, 0, 0);
}

int main(){
    cin >> l >> r;
    cout << f(r) - f(l - 1) << endl;
    return 0;
}