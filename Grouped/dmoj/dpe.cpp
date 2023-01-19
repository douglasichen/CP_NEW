#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAX_N=101, MAX_V=1e5+1;
const ll INF=1e10;
ll dp[MAX_N][MAX_V];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int y=0; y<MAX_N; y++)
		for (int x=1; x<MAX_V; x++)
			dp[y][x]=INF;

	int N,W; cin>>N>>W;	
	for (int i=1,w,v; i<=N; i++) {
		cin>>w>>v;
		for (int a=0; a<MAX_V; a++) {
			dp[i][a]=min(dp[i-1][a], (a-v>=0 ? dp[i-1][a-v]+w : INF));
		}
	}

	int ans=0;
	for (int v=MAX_V-1; v>=0; v--) {
		bool gd=0;
		for (int n=N; n>=0; n--) {
			if (dp[n][v]<=W) {
				gd=1;
				break;
			}
		}
		if (gd) {
			ans=v;
			break;
		}
	}
	cout << ans << endl;

}