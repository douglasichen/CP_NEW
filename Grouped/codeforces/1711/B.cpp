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
		int N,M; cin>>N>>M;
		vector<int> V(N), O(N);
		vector<vector<int>> G(N);
		for (int i=0; i<N; i++) cin>>V[i], O[i]=i;
		for (int i=0; i<M; i++) {
			int x,y; cin>>x>>y; x--, y--;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		for (int i=0; i<N; i++) sort(G[i].begin(), G[i].end());
		if (M&1) {
			auto srt=[&](int &a, int &b) {return V[a]<V[b];};
			sort(O.begin(), O.end(), srt);
			
			int ans=INT_MAX;
			vector<bool> done(N);
			for (int o : O) {
				if (G[o].size()&1) ans=min(ans,V[o]);
				else {
					for (int child : G[o]) {
						if (done[child]) ans=min(ans,V[o]+V[child]);
					}
				}
				done[o]=1;
			}
			if (ans==INT_MAX) {
				ans=0;
				for (int i : V) ans+=i;
			}
			cout << ans << endl;
		}
		else cout << 0 << endl;

	}
}