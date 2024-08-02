#include <iostream>
#include <vector>
using namespace std;

int main()
{
    freopen("hps.in", "r", stdin); freopen("hps.out", "w", stdout);
    int n;
    cin >> n;
    int hoof = 0, paper = 0, scissors = 0;
    // Create three arrays to get the total win of each type without changing
    vector<int> hoof_win(n), paper_win(n), scissor_win(n);
    for (int i = 0; i < n; i++){
        string c; cin >> c;
        if (c == "S")
            scissors++;
        else if (c == "P")
            paper++;
        else
            hoof++;
        hoof_win[i] = hoof; paper_win[i] = paper; scissor_win[i] = scissors;
    }
    // Determine switching point
    int max_win = 0;
    for (int i = 0; i < n; i++){
        int maximum = max(hoof_win[i], max(paper_win[i], scissor_win[i]));
        int switch_max = max((hoof_win[n - 1] - hoof_win[i]), max((paper_win[n - 1] - paper_win[i]), (scissor_win[n - 1] - scissor_win[i])));
        max_win = max(max_win, maximum + switch_max);
    }
    cout << max_win;
    return 0;
}