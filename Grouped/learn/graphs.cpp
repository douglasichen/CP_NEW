#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define F first

vector<vector<int>> G;

void dfs(int node) {
	for (int child : G[node]) {
		cout << node << "->" << child << endl;
		dfs(child);
	}
}

// dfs(1) - done computing

// node=1
// children: 4 - done, 5 - doing
// dfs(4) - done computing
// dfs(5)

// node=4
// children: 5
// dfs(5) - done computing

// node=5
// children: 

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	// N nodes numbered from 1 to N, M connections
	// N M
	// a1 b1
	// a2 b2


	int N,M; cin>>N>>M;
	G.resize(N+1);

	
	for (int i=0; i<M; i++) {
		int a,b; cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(1);
}