#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=10001, MAXM=1001, INF=1e9;
int dp[MAXN][MAXM], down[MAXN], up[MAXN], ans=INF, ans2=0;
bool no[MAXN][MAXM], has[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(dp,0);
	ms(no,0);
	ms(has,0);
	for (int x=1; x<MAXN; x++)
		for (int y=0; y<MAXM; y++)
			dp[x][y]=INF;

	int N,M,K; cin>>N>>M>>K;
	for (int i=0; i<N; i++) cin>>up[i]>>down[i];
	for (int k=0; k<K; k++) {
		int x,l,u; cin>>x>>l>>u;
		for (int y=1; y<=l; y++) no[x][y]=1;
		for (int y=u; y<=M; y++) no[x][y]=1;
		has[x]=1;
	}

	for (int x=0; x<N; x++) {
		int hit=0,a;
		for (int y=1; y<=M; y++) {			
			a=y-down[x];
			if (a>0 && !no[x+1][a] && !no[x][y]) dp[x+1][a]=min(dp[x+1][a], dp[x][y]);
			
			a=min(M,y+up[x]);
			if (!no[x+1][a]) dp[x+1][a]=min(dp[x+1][a], dp[x][y]+1);
			dp[x][a]=min(dp[x][a], dp[x][y]+1);

			if (dp[x][y]<INF) hit=1;
		}
		
		if (hit==0) break;
		if (has[x]) ans2++;
	}

	// for (int i=0; i<N; i++) cout << has[i] << ' '; cout << endl;

	for (int y=M; y; y--)
		for (int x=0; x<=N; x++)
			cout << (dp[x][y]==INF ? "x" : to_string(dp[x][y])) << (x==N ? "\n" : " ");

	for (int y=M; y; y--) 
		for (int x=0; x<=N; x++)
			cout << no[x][y] << (x==N ? "\n" : " ");


	for (int y=1; y<=M; y++) ans=min(ans, dp[N][y]);
	if (ans==INF) cout << 0 << endl << ans2 << endl;
	else cout << 1 << endl << ans << endl;
}