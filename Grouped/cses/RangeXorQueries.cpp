#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q; cin>>N>>Q;
	vector<long long> T(2*N);
	for (int i=0; i<N; i++) cin>>T[i+N];
	for (int i=N-1; i>0; i--) T[i]=T[i<<1]^T[(i<<1)+1];
	for (int i=0; i<Q; i++) {
		int a,b; cin>>a>>b; a--;
		int ans=0;
		for (a+=N, b+=N; a<b; a>>=1, b>>=1) {
			if (a&1) ans^=T[a++];
			if (b&1) ans^=T[--b];
		}
		cout << ans << endl;
	}
}