#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll getMaxArea(ll hist[], ll n){
    stack<ll> s;
    ll max_area = 0, tp, area_with_top;
    ll i = 0;
    while (i < n){
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else{
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            max_area = max(max_area, area_with_top);
        }
    }
    while (!s.empty()){
        tp = s.top(); s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
        max_area = max(max_area, area_with_top);
    }
    return max_area;
}
int main(){
    ll n; cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    cout << getMaxArea(a, n);
    return 0;
}