#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M; cin>>N>>M;
	vector<int> T(N<<1);
	for (int i=0; i<N; i++) cin>>T[i+N];
	for (int i=N-1; i>0; i--) T[i]=min(T[i<<1], T[i<<1|1]);
	for (int i=0; i<M; i++) {
		char c; int a, b; cin>>c>>a>>b;
		if (c=='M') {
			a+=N;
			T[a]=b;
			for (a>>=1; a; a>>=1) T[a]=min(T[a<<1], T[a<<1|1]);
		}
		else {
			int ans=T[a+N];
			for (a+=N, b+=N+1; a<b; a>>=1, b>>=1) {
				if (a&1) ans=min(ans,T[a]), a++;
				if (b&1) ans=min(ans,T[b-1]), b--;
			}
			cout << ans << endl;
		}
	}
}