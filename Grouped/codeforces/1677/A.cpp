#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		ll ans=0;
		int N; cin>>N;
		vector<int> V(N), F(N);
		for (int i=0; i<N; i++) cin>>V[i];
		for (int b=0; b<N; b++)
			for (int d=b+1; d<N; d++)
				F[b]+=V[b]>V[d];
		
		vector<int> psa(N);
		for (int c=1; c<N; c++) {
			for (int i=0; i<c; i++) F[i]-=V[i]>V[c];
			for (int i=0; i<N; i++) psa[i]=F[i]+(i ? psa[i-1] : 0);
			for (int a=0; a<c-1; a++) if (V[a]<V[c]) ans+=psa[c-1]-psa[a];
		}
		cout << ans << endl;
	}
}