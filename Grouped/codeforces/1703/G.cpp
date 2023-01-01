#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		ll N, K; cin>>N>>K;
		vector<ll> V(N), psa(N+1), hlf(N+1);
		for (int i=0; i<N; i++) cin>>V[i];
		for (int i=0; i<N; i++) {
			psa[i+1]=psa[i]+V[i];
			for (int o=0; i+o<N && o<29; o++)
				hlf[i]+=V[i+o]>>(o+1);
		}
		ll ans=LLONG_MIN;
		for (int i=0; i<=N; i++) {
			ll scr=psa[i]-i*K+hlf[i];
			ans=max(ans, scr);
		}
		cout << ans << endl;
	}
}