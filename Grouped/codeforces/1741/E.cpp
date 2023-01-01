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
		int N; cin>>N;
		vector<int> V(N);
		for (int &i : V) cin>>i;
		vector<vector<int>> G(N);
		for (int i=0; i<N; i++) {
			int a=i, b=i+V[i]+1;
			if (b<=N) G[a].push_back(b);
			a=i-V[i], b=i+1;
			if (b<=N && a>=0) G[a].push_back(b);
		}
		bool gd=0;
		vector<bool> vis(N+1);
		stack<int> S;
		vis[0]=1, S.push(0);
		while (!S.empty()) {
			int node=S.top(); S.pop();
			if (node==N) {
				gd=1;
				break;
			}
			for (int child : G[node]) {
				if (!vis[child]) {
					vis[child]=1;
					S.push(child);
				}
			}
		}
		cout << (gd ? "YES" : "NO") << endl;
	}
}