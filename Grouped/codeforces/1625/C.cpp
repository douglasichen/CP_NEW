#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int INF=((int)1e9)+1;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,L,K; cin>>N>>L>>K;
	vector<int> D(N+1), A(N); D[N]=L;
	for (int i=0; i<N; i++) cin>>D[i];
	for (int i=0; i<N; i++) cin>>A[i];
	
	vector<vector<int>> dp(N+1, vector<int>(K+1, INF)); // dp[i][j] = min(dp[i][j], dp[p][r]+(D[i]-D[p])*A[i]);
	dp[0][0]=0;
	for (int i=1; i<=N; i++) dp[i][0]=dp[i-1][0]+(D[i]-D[i-1])*A[i-1];
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=K; j++) {
			for (int p=0; p<i; p++) {
				int r=j-(i-p-1);
				if (r>=0) dp[i][j]=min(dp[i][j], dp[p][r]+(D[i]-D[p])*A[p]);
			}
		}
	}
	cout << *min_element(dp[N].begin(), dp[N].end()) << endl;
}