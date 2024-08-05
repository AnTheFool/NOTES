#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("pairup.in","r",stdin);
	freopen("pairup.out","w",stdout);

	int n, x, y; cin >> n;
	vector<int> cows;
	while(n--){
		cin >> x >> y;
		while(x--) cows.push_back(y);
	}
	sort(cows.begin(),cows.end());
	int l = -1, r = cows.size(), ans = 0;
	while(++l < --r) 
        ans = max(ans,cows[l]+cows[r]);
	cout << ans << endl;
}