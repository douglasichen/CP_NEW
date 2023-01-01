#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,K; cin>>N>>K;
	vector<vector<int>> V(N+1, vector<int>(2));
	for (int i=1; i<=N; i++) {
		cin>>V[i][0]>>V[i][1];
	}
	sort(V.begin()+1, V.end(), greater<vector<int>>());

	// for (int i=1; i<=N; i++) cout << V[i][0] << " " << V[i][1] << endl;

	ll INF=1e18;
	vector<vector<ll>> dp(N+1, vector<ll>(K+1,INF));
	for (int i=0; i<=N; i++) dp[i][0]=0;

	for (int i=1; i<=N; i++) {
		for (int k=1; k<=K; k++) {
			dp[i][k]=min(dp[i-1][k], dp[i-1][k-1] + 1LL*V[i][0]*(k-1) + V[i][1]);
		}
	}
	cout << dp[N][K] << endl;
}