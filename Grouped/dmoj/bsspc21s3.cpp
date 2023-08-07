#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=1e6+1;
ll psa[MAXN], dp[MAXN], ans=0;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	dp[0]=0;
	psa[0]=0;

	int N,K; cin>>N>>K;
	for (int i=1; i<=N; i++) {
		cin>>psa[i], psa[i]+=psa[i-1];
		if (i-K>=0) dp[i]=max(0LL, dp[i-K]+psa[i]-psa[i-K]), ans=max(ans, dp[i]);
	}
	cout << ans << endl;
}