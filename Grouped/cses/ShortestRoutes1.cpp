#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ll long long
 
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
 
	int N,M; cin>>N>>M;
	vector<vector<vector<ll>>> G(N);
	for (int i=0,a,b,c; i<M; i++) cin>>a>>b>>c, G[--a].push_back(vector<ll>{c,--b});
	
	vector<bool> vis(N);
	vector<ll> D(N, LLONG_MAX); D[0]=0;
	priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
	pq.push({0,0}); // dis, node
	while (pq.size()) {
		vector<ll> node=pq.top(); pq.pop();
		if (vis[node[1]]) continue;
		vis[node[1]]=1;
		
		for (vector<ll> &child : G[node[1]]) {
			if (vis[child[1]]) continue;
			ll nDis=node[0]+child[0];
			if (nDis<D[child[1]]) pq.push({nDis, child[1]}), D[child[1]]=nDis;
		}
	}
	for (ll &i : D) cout << i << ' '; cout << endl;

}