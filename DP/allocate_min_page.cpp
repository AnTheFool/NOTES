#include <bits/stdc++.h>
using namespace std;

int g(int x, int a[], int n){
    int num_students = 1, curr_pages = 0;
    for (int i = 0; i < n; i++){
        if (curr_pages + a[i] <= x){
            curr_pages += a[i];
        }
        else{
            curr_pages = a[i];
            num_students++;
        }
    }
    return num_students;
}

bool P(int x, int a[], int n, int m){
    return g(x, a, n) <= m;
}

int minPages(int a[], int n, int m){
    int low = *max_element(a, a + n);
    int high = accumulate(a, a + n, 0);
    if (P(low, a, n, m))
        return low;
    while (low < high - 1){
        int mid = low + (high - low) / 2;
        if (P(mid, a, n, m))
            high = mid;
        else
            low = mid;
    }
    return high;
}

int main(){
    int n, m, a[200000]; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << minPages(a, n, m);
    return 0;
}