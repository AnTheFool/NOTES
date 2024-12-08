#include <bits/stdc++.h>
using namespace std;

const int maxn = 500005;
const int LOG = 20;

int n, k, a[maxn];
int st_min[maxn][LOG], st_max[maxn][LOG];

// Xây dựng Sparse Table cho min và max
void buildSparseTable() {
    for (int i = 1; i <= n; i++) {
        st_min[i][0] = st_max[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
            st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// Truy vấn min/max trong đoạn [l, r]
int query_min(int l, int r) {
    int j = log2(r - l + 1);
    return min(st_min[l][j], st_min[r - (1 << j) + 1][j]);
}

int query_max(int l, int r) {
    int j = log2(r - l + 1);
    return max(st_max[l][j], st_max[r - (1 << j) + 1][j]);
}

// Kiểm tra xem đoạn [l, r] có hợp lệ không
bool isValid(int l, int r) {
    return query_max(l, r) - query_min(l, r) <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    buildSparseTable();

    long long ans = 0;
    for (int l = 1; l <= n; l++) {
        int lo = l, hi = n, r = l; // Khởi tạo binary search
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (isValid(l, mid)) {
                r = mid;
                lo = mid + 1; // Mở rộng đoạn về bên phải
            } else {
                hi = mid - 1; // Thu hẹp đoạn về bên trái
            }
        }
        ans += r - l + 1; // Cộng thêm số lượng đoạn hợp lệ
    }

    cout << ans << endl;
    return 0;
}