#include <bits/stdc++.h>
using namespace std;

bool myCmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int max_activities(pair<int, int> arr[], int n){
    sort(arr, arr + n, myCmp);
    int prev = 0, res = 1;
    for (int curr = 1; curr < n; curr++){
        if (arr[curr].first >= arr[prev].second){
            res++; prev = curr;
        }
    }
    return res;
}

int main(){
    int n; pair<int, int> arr[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    cout << max_activities(arr, n);
    return 0;
}