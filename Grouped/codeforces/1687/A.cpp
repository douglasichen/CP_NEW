#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ull unsigned long long

ull best(vector<int> &V, ull &N, ull &K) {
	ull sm=0, ans=0;
	for (int i=0; i<K; i++) sm+=V[i];
	ans=sm;
	for (int l=0, r=K; r<N; l++, r++) {
		sm-=V[l], sm+=V[r];
		ans=max(ans,sm);
	}
	return ans;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	ull ans, N, K, D;
	while (T--) {
		cin>>N>>K;
		ans=0;
		vector<int> V(N);
		for (int i=0, e; i<N; i++) cin>>e, V[i]=e, ans+=e;
		if (K<=N) ans=best(V, N, K)+K*(K-1)/2;
		else {
			K--;
			D=K-(N-1);
			ans+=D;
			D++;
			ans+=D*(N-1)+(N-1)*(N-2)/2;
		}
		cout << ans << endl;
		
	}
}