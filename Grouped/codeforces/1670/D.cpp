#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> dp;
	int add=-1, ans=0, i=0;
	for (i=0; ans<1e9; i++) {
		if (i%3==0 || i%3==2) add++;
		ans+=add<<1;
		dp.push_back(ans);
	}
	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		int e=lower_bound(dp.begin(), dp.end(), N)-dp.begin();
		cout << e << endl;
	}
}