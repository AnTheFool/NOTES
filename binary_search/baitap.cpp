#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m;
int a[100001], b[100001];

void nhap() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);  // Sắp xếp mảng độ khó các bài tập
}

bool check(int x, int k) {
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int diff = a[i + 1] - a[i];  // Chênh lệch giữa các bài hiện có
        cnt += (diff - 1) / x;  // Số bài cần thêm vào khoảng cách này để đảm bảo chênh lệch <= x
        if (cnt > k) return false;  // Nếu số bài cần thêm vượt quá k, trả về false
    }
    return cnt <= k;  // Trả về true nếu có thể thêm đủ bài mà chênh lệch <= x
}

int chat(int l, int r, int k) {
    int res = r;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid, k)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}

void solve() {
    if (n > m) {
        // Nếu n > m, chúng ta cần loại bỏ n - m bài
        for (int i = 1; i < n; i++)
            b[i] = a[i + 1] - a[i];  // Tính chênh lệch giữa các bài liên tiếp
        sort(b + 1, b + n);  // Sắp xếp chênh lệch
        cout << b[m] << endl;  // Chênh lệch lớn nhất giữa m bài sau khi loại bớt
    } else {
        // Nếu n < m, chúng ta cần thêm m - n bài
        int k = m - n;  // Số bài cần thêm
        int maxx = 0;
        for (int i = 1; i < n; i++)
            maxx = max(maxx, a[i + 1] - a[i]);  // Tìm chênh lệch lớn nhất hiện tại
        cout << chat(1, maxx, k) << endl;  // Tìm chênh lệch nhỏ nhất với bài thêm
    }
}

int main() {
    nhap();
    solve();
    return 0;
}
