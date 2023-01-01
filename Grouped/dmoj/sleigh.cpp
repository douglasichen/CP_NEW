#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<vector<int>>> G;

pair<int,int> bfs(int start) {
	pair<int,int> res={start,0};
	vector<bool> vis(N+1);
	vector<int> D(N+1);
	queue<int> Q;
	vis[start]=1;
	Q.push(start);
	while (!Q.empty()) {
		int node=Q.front(); Q.pop();
		if (D[node]>res.second) {
			res={node,D[node]};
		}
		for (vector<int> &child : G[node])
			if (!vis[child[0]])
				vis[child[0]]=1,
				D[child[0]]=D[node]+child[1],
				Q.push(child[0]);
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
    
    cin>>N;
    G.assign(N+1,{});
	long long tw=0;
    for (int i=0,a,b,c; i<N; i++) {
        cin>>a>>b>>c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
		tw+=c;
    }
	cout << 2*tw-bfs(0).second << endl;
}