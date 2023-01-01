#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll N,K; cin>>N>>K;
	vector<vector<ll>> V(K, vector<ll>(2));
	for (int i=0; i<K; i++) cin>>V[i][0]>>V[i][1];
	sort(V.begin(), V.end(), [](vector<ll> a, vector<ll> b) {
		return a[1]<b[1];
	});

	vector<ll> best(K);
	for (int i=0; i<K; i++) {
		if (i) best[i]=best[i-1];
		ll sm=V[i][1]-V[i][0]+1;
		
		int L=0, R=i-1;
		while (L<R) {
			int M=L+R+1>>1;
			if (V[M][1]<V[i][0]) L=M;
			else R=M-1;
		}
		if (V[L][1]<V[i][0]) sm+=best[L];
		best[i]=max(best[i], sm);
	}
	cout << N-best[K-1] << endl;
}