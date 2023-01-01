#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int N,M, pho[100000], cut[100000], vis[100000], D[100000], inDeg[100000];
vector<int> G[100000];
queue<int> Q;

pair<int,int> bfs(int start) {
	if (cut[start]) return {0,0};
	memset(vis, 0, sizeof(vis));
	memset(D, 0, sizeof(D));

	Q.push(start); vis[start]=1;
	pair<int,int> ret={0,0};
	while (!Q.empty()) {
		int node=Q.front(); Q.pop();
		ret={D[node], node};
		for (int child : G[node]) {
			if (!vis[child] && !cut[child]) {
				vis[child]=1;
				D[child]=D[node]+1;
				Q.push(child);
			}
		}
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	memset(pho, 0, sizeof(pho));
	memset(cut, 0, sizeof(cut));
	cin>>N>>M;
	for (int i=0,a; i<M; i++) cin>>a, pho[a]=1;
	for (int i=0; i<N-1; i++) {
		int a,b; cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
		inDeg[a]++;
		inDeg[b]++;
	}

	for (int i=0; i<N; i++) if (G[i].size()<=1) Q.push(i);
	while (!Q.empty()) {
		int node=Q.front(); Q.pop();
		if (cut[node]) continue;
		if (pho[node]) continue;
		cut[node]=1;
		for (int child : G[node]) {
			inDeg[child]--;
			if (!cut[child] && inDeg[child]<=1) 
				Q.push(child);
		}
	}
	int start=0;
	for (int i=0; i<N; i++) if (!cut[i]) start=i;
	int lPath=bfs(bfs(start).second).first; // length, end.
	int totW=max(N-accumulate(cut, cut+N, 0)-1,0);
	int ans=2*totW-lPath;
	cout << ans << endl;
}