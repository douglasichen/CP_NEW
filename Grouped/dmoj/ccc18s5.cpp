// connections can be sorted by smallest cost
// the edges can be added in non-decreasing order of cost
// isnt this just MST?
// but I have to be careful about the number of edges I compute...
// nvm only P edges 
// so just MST where I label all cities with unique ID: planetId*M + cityNum
// and just cost of graph - cost of MST


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int MAXN=1e5+1;
vector<vector<ll>> G[MAXN];
bitset<100001> vis;

ll ans=0;

void mst(int F) {
	ll cost=0;
	vis=0;
	priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
	pq.push({0,1});
	while (SZ(pq)) {
		vector<ll> node=pq.top(); pq.pop();
		if (vis[node[1]]) continue;
		vis[node[1]]=1;
		cost+=node[0];

		for (vector<ll> child : G[node[1]]) {
			if (!vis[child[1]]) {
				pq.push(child);
			}
		}
	}
	cout << cost << endl;
	ans-=cost*F;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int A=0,B=0;

	int N,M,P,Q; cin>>N>>M>>P>>Q;
	ll a,b,c;
	for (int i=0; i<P; i++) {
		cin>>a>>b>>c; // c is cost from cities a->b
		G[a].push_back({c,b});
		G[b].push_back({c,a});
		ans+=c*N;
		A+=c*N;
	}
	mst(N);

	ms(G,0);
	for (int i=0; i<Q; i++) {
		cin>>a>>b>>c; // c is cost from planets a->b
		G[a].push_back({c,b});
		G[b].push_back({c,a});
		ans+=c*M;
		B+=c*M;
	}
	mst(1);

	cout << ans << endl;

	cout << A << " " << B << endl;
}