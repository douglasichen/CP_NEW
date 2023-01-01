#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int N,M;
vector<vector<vector<int>>> G;

vector<int> D;

vector<int> hit, from;
vector<int> done(2000000);

int ans=INT_MAX;
void dfs(vector<int> node) {
	hit[node[1]]=1;
	for (vector<int> child : G[node[1]]) {
		if (done[child[1]]) continue;
		if (from[node[1]]==child[1]) continue;
		// cout << node[1] << "->" << child[1] << endl;
		if (!hit[child[1]]) from[child[1]]=node[1], dfs({node[0]+child[0], child[1]});
		else {
			done[node[1]]=1;
			ans=min(ans,node[0]+child[0]+D[child[1]]);
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	hit.assign(N+1,0);
	from.assign(N+1,0);
	G=vector<vector<vector<int>>>(N+1);
	D.assign(N+1,0);
	for (int i=0; i<M; i++) {
		int a,b,c; cin>>a>>b>>c;
		G[a].push_back({c,b});
		G[b].push_back({c,a});
	}
	int A,B; cin>>A>>B;
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	pq.push({0,B});
	vector<int> vis(N+1);
	while (!pq.empty()) {
		vector<int> back=pq.top(); pq.pop();
		if (vis[back[1]]) continue;
		vis[back[1]]=1;
		D[back[1]]=back[0];

		for (vector<int> child : G[back[1]]) {
			if (!vis[child[1]]) {
				pq.push({back[0]+child[0], child[1]});
			}
		}
	}
	dfs({0,A});
	if (ans==INT_MAX) cout << -1 <<endl;
	else cout << ans << endl;
}