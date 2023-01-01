#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	short T; cin>>T;
	while (T--) {
		short N,K; cin>>N>>K;
		vector<short> V(N);
		short mn=3001;
		for (short i=0; i<N; i++) cin>>V[i], mn=min(mn,V[i]);
		bool big=1;
		for (short i : V) if (i>=K) big=0;
		
		short ans=30001;
		if (big) ans=0;
		for (short e=1; e<=mn; e++) {
			short A=3001,B=0;
			for (short i : V) {
				short div=i/e;
				div=min(div,K);
				short val=i/div;
				A=min(A,val), B=max(B,val);
			}
			ans=min(ans, (short)(B-A));
		}
		cout << ans << endl;
	}
}