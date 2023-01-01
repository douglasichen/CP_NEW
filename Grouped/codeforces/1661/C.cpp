#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

bool gd(vector<ll> V, ll ones, ll twos) {
	for (ll &e : V) {
		ll cnt=min(e/2, twos);
		e-=cnt*2;
		twos-=cnt;
	}
	for (ll &e : V) {
		ll cnt=min(e, ones);
		e-=cnt;
		ones-=cnt;
		if (e) return 0;
	}
	return 1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll L, R, mid, T, N, mx, sm, ones, twos;

	cin>>T;
	while (T--) {
		cin>>N;
		vector<ll> H(N);
		mx=0;
		for (int i=0; i<N; i++) cin>>H[i], mx=max(mx,H[i]);
		for (int i=0; i<N; i++) H[i]=mx-H[i];
		
		L=0, R=3e14;
		while (L<R) {
			vector<ll> V=H, V2=H;
			for (ll &e : V2) e++;

			mid=(L+R)/2;
			ones=(mid+1)/2;
			twos=mid/2;

			if (gd(V, ones, twos) || gd(V2, ones, twos)) R=mid;
			else L=mid+1;
		}
		cout << R << endl;
	}
}