#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200007
int n, q;
int p[maxn];
ll down_node[4 * maxn], up_node[4 * maxn];

// Hàm cập nhật cho cây Segment Tree
void update(ll node[], int id, int l, int r, int pos, ll val) {
    if (pos < l || pos > r) // Nếu pos nằm ngoài đoạn [l, r], bỏ qua nút id
        return;
    if (l == r) { // Đoạn chỉ gồm 1 phần tử, cập nhật giá trị cho nút lá
        node[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    // Gọi đệ quy để xử lý các nút con của nút id
    update(node, id * 2, l, mid, pos, val);
    update(node, id * 2 + 1, mid + 1, r, pos, val);
    // Cập nhật lại giá trị cho nút id là giá trị min của 2 nút con
    node[id] = min(node[id * 2], node[id * 2 + 1]);
}

// Hàm truy vấn min trên đoạn [x, y]
ll get_min(ll node[], int id, int l, int r, int x, int y) {
    if (l > y || r < x) // Đoạn [x, y] không giao với đoạn [l, r], bỏ qua
        return 1e9; // Giá trị vô cùng lớn cho min
    if (l >= x && r <= y) // Đoạn [l, r] nằm hoàn toàn trong đoạn [x, y]
        return node[id];
    int mid = (l + r) / 2;
    // Gọi đệ quy với các nút con của nút id và lấy min của chúng
    ll left_min = get_min(node, id * 2, l, mid, x, y);
    ll right_min = get_min(node, id * 2 + 1, mid + 1, r, x, y);
    return min(left_min, right_min);
}

// Hàm cập nhật giá trị cho các cây `down` và `up`
void pull(int i) {
    update(down_node, 1, 1, n, i, p[i] - i);
    update(up_node, 1, 1, n, i, p[i] + i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) cin >> p[i];
    // Khởi tạo các cây `down` và `up` với giá trị ban đầu
    for (int i = 1; i <= n; i++) pull(i);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, x;
            cin >> k >> x;
            p[k] = x;
            pull(k); // Cập nhật lại cây khi giá trị p[k] thay đổi
        } else {
            int k;
            cin >> k;
            ll D = get_min(down_node, 1, 1, n, 1, k) + k;
            ll U = get_min(up_node, 1, 1, n, k, n) - k;
            cout << min(D, U) << '\n';
        }
    }

    return 0;
}
