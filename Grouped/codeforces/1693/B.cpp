#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int TC; cin>>TC;
	while (TC--) {
		int N; cin>>N;
		vector<int> P(N+1), cCnt(N+1);
		vector<bool> isLeaf(N+1,1);
		for (int i=2; i<=N; i++) cin>>P[i], isLeaf[P[i]]=0, cCnt[P[i]]++;
		vector<vector<long long>> R(N+1, vector<long long>(2));
		for (int i=1; i<=N; i++) cin>>R[i][0]>>R[i][1];

		int ans=0;
		vector<long long> dp(N+1);
		queue<int> Q;
		for (int i=1; i<=N; i++) if (isLeaf[i]) Q.push(i);
		while (!Q.empty()) {
			int node=Q.front(), par=P[node]; Q.pop();
			if (dp[node]<R[node][0]) ans++, dp[node]=R[node][1];
			else dp[node]=min(dp[node], R[node][1]);

			dp[par]+=dp[node];
			cCnt[par]--;
			if (cCnt[par]==0) Q.push(par);
		}
		cout << ans << endl;
	}
}