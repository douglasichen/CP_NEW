#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q; cin>>N>>Q;
	vector<int> T(2*N);
	for (int i=0; i<N; i++) cin>>T[i+N];
	for (int i=N-1; i>0; i--) T[i]=min(T[i<<1],T[(i<<1)+1]);
	for (int i=0; i<Q; i++) {
		int x,a,b; cin>>x>>a>>b; a--;
		if (x==1) {
			for (T[a+=N]=b; a>0; a>>=1) T[a>>1]=min(T[a],T[a^1]);
		}
		else {
			int ans=T[a+N];
			for (a+=N, b+=N; a<b; a>>=1, b>>=1) {
				if (a&1) ans=min(ans,T[a++]);
				if (b&1) ans=min(ans,T[--b]);
			}
			cout << ans << endl;
		}
	}	
}