#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	vector<int> D(1001);
	queue<int> Q; Q.push(1);
	while (!Q.empty()) {
		int b=Q.front(); Q.pop();
		for (int x=1; x<=b; x++) {
			int val=b+b/x;
			if (val<=1e3 && !D[val]) D[val]=D[b]+1, Q.push(val);
		}
	}

	int T; cin>>T;
	while (T--) {
		int N,K; cin>>N>>K;
		K=min(K,12000);
		vector<int> W(N+1), B(N+1), C(N+1);
		for (int i=1, b; i<=N; i++) cin>>b, W[i]=D[b];
		for (int i=1; i<=N; i++) cin>>C[i];

		vector<vector<int>> dp(K+1, vector<int>(N+1));
		for (int k=0; k<=K; k++) 
			for (int i=1; i<=N; i++) 
				dp[k][i]=max(dp[k][i-1], (W[i]>k ? 0 : dp[k-W[i]][i-1]+C[i]));

		cout << dp[K][N] << endl;
	}
}