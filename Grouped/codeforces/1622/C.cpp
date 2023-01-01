#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

ll flr(ll a, ll b) {
	ll ans=a/b;
	while (ans*b>a) ans--;
	return ans;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		ll N,K; cin>>N>>K;
		vector<ll> V(N+1), psa(N+1);
		for (int i=1; i<=N; i++) cin>>V[i];
		sort(V.begin()+1, V.end(), greater<ll>());
		for (int i=1; i<=N; i++) psa[i]=psa[i-1]+V[i];

		ll ans=LLONG_MAX;
		for (ll y=0; y<N; y++) {
			ll x=V[N]-flr(K-(psa[N-1]-psa[y]), y+1);
			ans=min(ans, max(x,0LL)+y);
		}
		cout << ans << endl;
	}
}