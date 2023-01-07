#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int MAXC=1e5+1;
int C,R,D, dest[MAXC], vis[MAXC], deg[MAXC];
vector<vector<int>> G[MAXC], mst[MAXC];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>C>>R>>D;
	for (int i=0; i<R; i++) {
		int x,y,w; cin>>x>>y>>w;
		G[x].push_back({w,y});
		G[y].push_back({w,x});
	}	
	for (int i=0,a; i<D; i++) {
		cin>>a;
		dest[a]=1;
	}

	memset(vis,0,sizeof(vis));
	memset(deg, 0, sizeof(deg));

	priority_queue<vector<int>, vector<vector<int>>> pq;
	pq.push({0,1,0}); // weight, node, from
	while (!pq.empty()) {
		vector<int> top=pq.top(); pq.pop();
		if (vis[top[1]]) continue;
		vis[top[1]]=1;

		if (top[2]) {
			mst[top[2]].push_back({top[0], top[1]});
			mst[top[1]].push_back({top[0], top[2]});
			
			deg[top[2]]++;
			deg[top[1]]++;
		}

		for (vector<int> child : G[top[1]]) {
			if (!vis[child[1]]) {
				pq.push({child[0],child[1], top[1]});
			}
		}
	}


	memset(vis, 0, sizeof(vis));

	stack<int> q;
	for (int i=2; i<=C; i++) if (deg[i]==1 && !dest[i]) q.push(i), vis[i]=1;
	while (q.size()) {
		int node=q.top(); q.pop();
		for (vector<int> child : mst[node]) {
			deg[child[1]]--;
			if (!vis[child[1]] && !dest[child[1]] && deg[child[1]]<=1 && child[1]!=1) {
				vis[child[1]]=1;
				q.push(child[1]);
			}
		}
	}
	
	vis[0]=1;
	q.push(1);
	int ans=1e5+1;
	while (q.size()) {
		int node=q.top(); q.pop();
		for (vector<int> child : mst[node]) {
			if (!vis[child[1]]) {
				vis[child[1]]=1;
				q.push(child[1]);
				ans=min(ans,child[0]);
			}
		}
	}
	cout << ans << endl;
}