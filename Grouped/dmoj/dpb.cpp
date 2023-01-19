#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=1e5;
int dp[MAXN], h[MAXN], INF=1e9;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	fill(dp,dp+MAXN,INF);

	int N,K; cin>>N>>K;
	for (int i=0; i<N; i++) cin>>h[i];

	dp[0]=0;
	for (int i=1; i<N; i++) {
		for (int l=max(0,i-K); l<i; l++) {
			dp[i]=min(dp[i], dp[l]+abs(h[i]-h[l]));
		}
	}
	cout << dp[N-1] << endl;
}