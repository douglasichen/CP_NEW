#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int N;
vector<vector<int>> G;
pair<int,int> bfs(int start) {
	pair<int,int> res={start,0};
	vector<bool> vis(N+1);
	vector<int> D(N+1,0);
	queue<int> Q;
	Q.push(start), vis[start]=1;
	while (!Q.empty()) {
		int node=Q.front(); Q.pop();
		res.first=node;
		res.second=D[node];
		for (int &child : G[node])
			if (!vis[child])
				vis[child]=1,
				D[child]=D[node]+1,
				Q.push(child);
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	G.assign(N+1,{});
	for (int i=0,a,b; i<N-1; i++)
		cin>>a>>b,
		G[a].push_back(b),
		G[b].push_back(a);
	cout << bfs(bfs(1).first).second << endl;
}