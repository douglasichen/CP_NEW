#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T,N,M,a,b,md=1e9+7; cin>>T;
	while (T--) {
		cin>>N>>M;
		vector<vector<long long>> dp(N, vector<long long>(M+1));
		cin>>a>>b;
		for (int i=a; i<=b; i++) if (i<=M) dp[0][i]++;
		for (int i=1; i<N; i++) {
			cin>>a>>b;
			for (int e=a; e<=b; e++) {
				for (int p=1; p<=M; p++) {
					if (dp[i-1][p]) {
						int sm=e+p;
						if (sm<=M) dp[i][sm]+=dp[i-1][p];
					}
				}
			}
		}
		long long ans=dp[N-1][M]%md;
		cout << ans << endl;
	}
}