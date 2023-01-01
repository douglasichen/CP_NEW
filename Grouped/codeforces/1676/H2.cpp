#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		ll ans=0;
		vector<ll> T(N<<1), F(N), V(N);
		for (int i=0; i<N; i++) cin>>V[i], V[i]--, F[V[i]]++;
		for (ll i : F) ans+=(i*(i-1)>>1);
		for (int i=0; i<N; i++) {
			int to=V[i]+N;
			T[to]++;
			for (to>>=1; to; to>>=1) T[to]=T[to<<1]+T[to<<1|1];
			
			ll sm=0;
			int L=V[i]+1, R=N;
			for (L+=N, R+=N; L<R; L>>=1, R>>=1) {
				if (L&1) sm+=T[L++];
				if (R&1) sm+=T[--R];
			}
			ans+=sm;
		}
		cout << ans << endl;
	}	
}