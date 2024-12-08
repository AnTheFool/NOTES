#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MOD = 1000000007;
const int MAX_SUM = 1800;  // Max sum of digits in a 200-digit number is at most 1800

// DP cache
int dp[201][MAX_SUM + 1][2];

// Check if a number is prime
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// List to store prime status up to MAX_SUM
vector<bool> primeCache;

// Initialize prime cache
void initPrimeCache() {
    primeCache.resize(MAX_SUM + 1, false);
    for (int i = 2; i <= MAX_SUM; ++i) {
        if (isPrime(i)) {
            primeCache[i] = true;
        }
    }
}

// Digit DP to count numbers <= X with prime digit sum
int countWithPrimeSum(const string &X, int idx, int sum, bool small) {
    if (idx == X.size()) {
        return primeCache[sum] ? 1 : 0;
    }
    if (dp[idx][sum][small] != -1) {
        return dp[idx][sum][small];
    }

    int limit = small ? 9 : (X[idx] - '0');
    int res = 0;

    for (int d = 0; d <= limit; ++d) {
        res = (res + countWithPrimeSum(X, idx + 1, sum + d, small || (d < limit))) % MOD;
    }

    dp[idx][sum][small] = res;
    return res;
}

// Calculate count of numbers <= X with prime digit sum
int calc(const string &X) {
    memset(dp, -1, sizeof(dp));
    return countWithPrimeSum(X, 0, 0, 0);
}

// Function to decrement a number represented as a string
string decrementOne(const string &X) {
    string result = X;
    int n = result.size();
    for (int i = n - 1; i >= 0; --i) {
        if (result[i] > '0') {
            result[i]--;
            break;
        } else {
            result[i] = '9';
        }
    }
    if (result[0] == '0') result.erase(result.begin());
    return result;
}

int main() {
    initPrimeCache();  // Initialize prime number cache

    int T;
    cin >> T;
    while (T--) {
        string L, R;
        cin >> L >> R;

        int resR = calc(R);
        int resL = calc(decrementOne(L));

        int result = (resR - resL + MOD) % MOD;
        cout << result << endl;
    }

    return 0;
}