#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight, value;
};

bool cmp(Item &a, Item &b){
    return (1.0 * a.value / a.weight) > (1.0 * b.value / b.weight);
}

int main(){
    int n, w; cin >> n >> w;
    vector<Item> items;
    for (int i = 0; i < n; i++){
        int weights, values; cin >> weights >> values;
        items.push_back({weights, values});
    }
    sort(items.begin(), items.end(), cmp);
    double ans = 0;
    for (int i = 0; i < n; i++){
        int x = min(items[i].weight, w);
        ans += x * 1.0 * items[i].value / items[i].weight;
        w -= x;
    }
    cout << ans << endl;
    return 0;
}