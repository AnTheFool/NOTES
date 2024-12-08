#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100007
int n, q, a[maxn]; ll node[4 * maxn];

void update(int id, int l, int r, int pos, ll val){
    // pos nằm ngoài đoạn [l, r], ta bỏ qua nút id
    if (pos < l || pos > r)
        return;
    // Đoạn chỉ gồm 1 phần tử, không có nút con
    if (l == r){
        node[id] = val;
        return;
    }
    // Gọi đệ quy để xử lý các nút con của nút id
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    // Cập nhật lại giá trị tổng của đoạn [l, r] theo 2 nút con
    node[id] = node[id * 2] + node[id * 2 + 1];
}

ll get(int id, int l, int r, int x, int y){
    if (l > y || r < x) // Đoạn [x, y] không giao với đoạn [l, r], ta bỏ qua đoạn này
        return 0;
    /* Đoạn [l, r] nằm hoàn toàn trong đoạn [x, y] mà ta đang truy vấn,
        ta trả lại thông tin lưu ở nút id */
    if (l >= x && r <= y)
        return node[id];
    // Gọi đệ quy với các nút con của nút id
    int mid = (l + r) / 2;
    ll get_l = get(id * 2, l, mid, x, y);
    ll get_r = get(id * 2 + 1, mid + 1, r, x, y);
    // Tính tổng cho đoạn [x, y] bằng cách cộng 2 tổng cho các đoạn
    return get_l + get_r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        a[i] = 0;
    while (q--){
        int type, x, y; cin >> type >> x >> y;
        if (type == 1)
            update(1, 1, n, x, y);
        else
            cout << get(1, 1, n, x, y) << "\n";
    }
    return 0;
}