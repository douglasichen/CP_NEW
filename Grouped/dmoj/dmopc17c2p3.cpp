#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, R; cin>>N>>R;
	vector<vector<int>> G(N+1);
	for (int i=0,a,b; i<N-1; i++) {
		cin>>a>>b,
		G[a].push_back(b);
		G[b].push_back(a);
	}
	queue<int> Q;
	vector<int> D(N+1, INT_MAX);
	for (int i=0,r; i<R; i++) {
		cin>>r;
		Q.push(r);
		D[r]=0;
	}
	while (!Q.empty()) {
		int node=Q.front(); Q.pop();
		for (int child : G[node]) {
			int nDis=D[node]+1;
			if (nDis<D[child]) {
				D[child]=nDis;
				Q.push(child);
			}
		}
	}
	int A, B; cin>>A>>B;
	vector<int> vis(N+1), pre(N+1);
	vis[A]=1;
	Q.push(A);
	while (!Q.empty()) {
		int node=Q.front(); Q.pop();
		if (node==B) break;
		for (int child : G[node]) {
			if (!vis[child]) {
				vis[child]=1;
				pre[child]=node;
				Q.push(child);
			}
		}
	}

	int ans=INT_MAX;
	while (B) {
		ans=min(ans,D[B]);
		B=pre[B];
	}
	cout << ans << endl;
}