#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589793

const double EPS = 1e-9;

double b, c;

double f(double x) {
    // Function to be minimized
    return (x * x + b * x + c) / sin(x);
}

double ternarySearch(double lo, double hi) {
    while (hi - lo > EPS) {
        double mid1 = lo + (hi - lo) / 3.0;
        double mid2 = hi - (hi - lo) / 3.0;
        double y1 = f(mid1);
        double y2 = f(mid2);
        if (y1 > y2) {
            lo = mid1;
        } else {
            hi = mid2;
        }
    }
    return f(lo);
}

int main(){
    cin >> b >> c;
    double lo = 0.0, hi = PI / 2.0;
    double ans = ternarySearch(lo, hi);
    cout << fixed << setprecision(9) << ans << endl;
    return 0;
}