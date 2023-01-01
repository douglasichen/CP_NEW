#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		long long N, ans=0, at=0; cin>>N;
		vector<long long> V(N), D(N);
		for (int i=0; i<N; i++) cin>>V[i];
		for (int i=1; i<N; i++) D[i]=V[i]-V[i-1];
		at=V[0];
		long long delta=0;
		for (int i=1; i<N; i++) {
			ans+=abs(D[i]);
			if (D[i]<0) {
				at+=D[i];
			}
		}
		ans+=abs(at);
		cout << ans << endl;
	}	
}