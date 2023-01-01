#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N,K; cin>>N>>K;
		bool gd[N+1][N+1];
		char c;
		for (int y=1; y<=N; y++)
			for (int x=1; x<=N; x++)
				cin>>c, gd[y][x]=(c=='.');
		long long dp[N+1][N+1][K+1][2];
		for (int a=0; a<=N; a++)
			for (int b=0; b<=N; b++)
				for (int c=0; c<=K; c++)
					for (int d=0; d<2; d++)
						dp[a][b][c][d]=0;
		for (int y=2; y<=N; y++) {
			if (!gd[y][1]) break;
			dp[y][1][0][0]=1;
		}
		for (int x=2; x<=N; x++) {
			if (!gd[1][x]) break;
			dp[1][x][0][1]=1;
		}
		for (int y=2; y<=N; y++)
			for (int x=2; x<=N; x++)
				for (int k=1; k<=K; k++)
					dp[y][x][k][0] = (dp[y-1][x][k][0] + dp[y-1][x][k-1][1])*gd[y][x],
					dp[y][x][k][1] = (dp[y][x-1][k-1][0] + dp[y][x-1][k][1])*gd[y][x];
		long long ans=0;
		for (int k=1; k<=K; k++)
			for (int i=0; i<2; i++)
				ans+=dp[N][N][k][i];
		cout << ans << endl;
	}	
}