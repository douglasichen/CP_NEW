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
		int N,Q; cin>>N>>Q;
		vector<int> V(N+1), M(N+2);
		for (int i=1; i<=N; i++) cin>>V[i], M[V[i]]=i;
		for (int i=N-1; i; i--) M[i]=min(M[i], M[i+1]);
		while (Q--) {
			int P,K,ans=0; cin>>P>>K;
			int J=M[V[P]+1], R=max(0,K-max(0,P-2));

			if (V[P]==N) ans=R;
			else if (J>P) ans+=min(R,J-P-1+(P!=1));
			
			cout << ans << endl;
		}
	}
}