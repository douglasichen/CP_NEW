#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define SZ(a) int(a.size())
#define endl '\n'
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=1e5+1;
const ll INF=1e10;
ll dp[MAXN][2];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	for (int i=0; i<MAXN; i++)
		for (int x=0; x<2; x++)
			dp[i][x]=-INF;

	int N; cin>>N;
	for (int i=1; i<=N; i++) {
		ll a; cin>>a;
		if (a&1) {
			dp[i][1]=max({a, dp[i-1][0]+a, dp[i-1][1]});
			dp[i][0]=max(dp[i-1][0], dp[i-1][1]+a);
		}
		else {
			dp[i][1]=max(dp[i-1][1], dp[i-1][1]+a);
			dp[i][0]=max({a, dp[i-1][0]+a, dp[i-1][0]});
		}
	}
	cout << dp[N][1] << endl;
}