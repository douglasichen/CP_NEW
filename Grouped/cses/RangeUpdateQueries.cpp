#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q; cin>>N>>Q;
	vector<long long> T(N*2);
	for (int i=0; i<N; i++) cin>>T[i+N];
	for (int i=0; i<Q; i++) {
		int x; cin>>x;
		if (x==1) {
			int a,b,u; cin>>a>>b>>u; a--;
			for (a+=N, b+=N; a<b; a>>=1, b>>=1) {
				if (a&1) T[a++]+=u;
				if (b&1) T[--b]+=u;
			}
		}
		else {
			int p; cin>>p; p--;
			long long ans=0;
			for (p+=N; p>0; p>>=1) ans+=T[p];
			cout << ans << endl;
		}
	}
}