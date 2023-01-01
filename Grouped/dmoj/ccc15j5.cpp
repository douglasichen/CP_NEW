#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,K; cin>>N>>K;
	int dp[N+1][K+1][N+1];
	for (int a=0; a<=N; a++) for (int b=0; b<=K; b++) for (int c=0; c<=N; c++) dp[a][b][c]=0;
	for (int n=1; n<=N; n++) dp[n][1][n]=1;
	for (int k=2; k<=K; k++) 
		for (int n=k; n<=N; n++) 
			for (int m=n-(k-1); m>0; m--) 
				for (int x=m; x; x--)
					dp[n][k][m]+=dp[n-m][k-1][x];
	int ans=0;
	for (int m=1; m<=N; m++) ans+=dp[N][K][m];
	cout << ans << endl;
}