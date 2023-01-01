#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	vector<int> cnts(1e7+1);
	vector<bool> iP(1e7+1,1);
	int mxCnt=0;
	for (int i=2; i<=1e7; i++) {
		if (!iP[i]) continue;
		int at=i;
		while (at<=1e7) {
			iP[at]=0;
			cnts[at]++;
			mxCnt=max(mxCnt, cnts[at]);
			at+=i;
		}
	}
	vector<vector<int>> M(mxCnt+1);
	for (int i=2; i<=1e7; i++) M[cnts[i]].push_back(i);

	int T; cin>>T;
	for (int t=1, A, B, K; t<=T; t++) {
		cin>>A>>B>>K;
		auto a=lower_bound(M[K].begin(), M[K].end(), A);
		auto b=upper_bound(M[K].begin(), M[K].end(), B);
		int ans=b-a;
		cout << "Case #" << t << ": " << ans << endl;
	}	
}