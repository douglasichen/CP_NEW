#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define SZ(a) int(a.size())
#define ms(a,b) memset(a,b,sizeof(a))
#define pii pair<ll,ll>

const int MAXN=11;
ll ar[MAXN];


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		for (int i=1; i<=N; i++) cin>>ar[i];
		ar[0]=0;
		
		vector<vector<pair<ll,ll>>> dp(N+1);
		dp[1].push_back({ar[1],ar[1]});

		for (int i=2; i<=N; i++) {
			for (pii ran : dp[i-1]) {
				dp[i].push_back({min(ran.first,ar[i]), max(ran.second,ar[i])});
			}

			if (i==2) dp[i].push_back({ar[i]+ar[i-1],ar[i]+ar[i-1]});
			for (pii ran : dp[i-2]) {
				dp[i].push_back({min(ran.first,ar[i]+ar[i-1]), max(ran.second,ar[i]+ar[i-1])});
			}
		}

		ll ans=LLONG_MAX;
		for (pii p : dp[N]) ans=min(ans, ll(p.second-p.first));
		cout << ans << endl;
	}

}