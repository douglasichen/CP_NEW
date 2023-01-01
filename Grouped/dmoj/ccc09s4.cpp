#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,T,K,D; cin>>N>>T;
	vector<vector<int>> G(N+1, vector<int>(N+1, INT_MAX));
	for (int t=0,a,b,cost; t<T; t++)
		cin>>a>>b>>cost, 
		G[a][b]=min(G[a][b], cost),
		G[b][a]=G[a][b];
	
	cin>>K;
	vector<vector<int>> P(K, vector<int>(2));
	for (int k=0; k<K; k++) cin>>P[k][0]>>P[k][1];
	
	cin>>D;
	vector<int> vis(N+1), dis(N+1, INT_MAX);
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	pq.push({0,D}), dis[D]=0;
	while (!pq.empty()) {
		vector<int> node=pq.top(); pq.pop();
		if (vis[node[1]]) continue;
		vis[node[1]]=1;

		for (int child=1; child<=N; child++) {
			if (!vis[child] && G[node[1]][child]!=INT_MAX) {
				int nDis=G[node[1]][child]+node[0];
				if (nDis<dis[child]) dis[child]=nDis, pq.push({nDis,child});
			}
		}
	}

	int ans=INT_MAX;
	for (vector<int> p : P) ans=min(ans, p[1]+dis[p[0]]);
	cout << ans << endl;
}