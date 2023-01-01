#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int N,M; 
vector<vector<int>> G;
vector<int> ts, deg;
vector<bool> vis0, vis1;

void dfs(int at) {
	vis1[at]=1;
	vis0[at]=1;
	for (int child : G[at]) {
		if (!vis1[child]) dfs(child);
		else if (vis0[child]) return;
	}
	vis0[at]=0;
	ts.push_back(at);
	if (ts.size()==N) reverse(ts.begin(),ts.end());
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	G.assign(N+1,{});
	vis0.assign(N+1,0);
	vis1.assign(N+1,0);
	deg.assign(N+1,0);
	for (int i=0,a,b; i<M; i++) cin>>a>>b, G[a].push_back(b), deg[b]++;

	for (int i=1; i<=N; i++) {
		if (deg[i]==0) dfs(i);
	}

	if (ts.size()!=N) cout << "cycle" << endl;
	else {
		for (int i : ts) cout << i << ' ';
		cout << endl;
	}
}