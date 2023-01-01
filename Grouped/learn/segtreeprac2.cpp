#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int TC, N; cin>>N>>TC;
	ll ans;
	vector<ll> T(N<<1);
	for (int i=0; i<N; i++) cin>>T[i+N];
	for (int i=N-1; i; i--) T[i]=T[i<<1]+T[i<<1|1];
	for (int a,b,c; TC; TC--) {
		cin>>a>>b>>c; b--;
		if (a==1) {
			T[b+N]=c;
			b=b+N>>1;
			for (; b; b>>=1) T[b]=T[b<<1]+T[b<<1|1];
		}
		else {
			ans=0;
			for (b+=N, c+=N; b<c; b>>=1, c>>=1) {
				if (b&1) ans+=T[b++];
				if (c&1) ans+=T[--c];
			}
			cout << ans << endl;
		}
	}
	// for (int i : T) cout << i << ' '; cout << endl;
}