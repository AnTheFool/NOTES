#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_SIDE = 1000;
int tree_pref[MAX_SIDE + 1][MAX_SIDE + 1];
int forest[MAX_SIDE + 1][MAX_SIDE + 1];

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char c; cin >> c;
            forest[i + 1][j + 1] += (c == '*');
        }
    }
    // 2D prefix sum
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            tree_pref[i][j] = tree_pref[i - 1][j] + tree_pref[i][j - 1] + forest[i][j] - tree_pref[i - 1][j - 1];
    }

    while (q--){
        int x1, x2, y1, y2; cin >> y1 >> x1 >> y2 >> x2;
        cout << tree_pref[y2][x2] - tree_pref[y1 - 1][x2] - tree_pref[y2][x1 - 1] + tree_pref[y1 - 1][x1 - 1] << "\n";
    }
    return 0;
}