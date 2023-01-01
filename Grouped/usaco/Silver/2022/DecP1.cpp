#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> V(N+1), D(N+1);
	ll sm=0;
	for (int i=1; i<=N; i++) cin>>V[i], sm+=V[i];
	sm/=N;
	for (int i=1; i<=N; i++) D[i]=sm-V[i];

	vector<vector<int>> G(N+1);
	for (int i=0,a,b; i<N-1; i++) {
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int root=0;
	queue<int> Q;
	vector<int> vis(N+1);
	for (int i=1; i<=N; i++) if (G[i].size()==1) Q.push(i), vis[i]=1;
	while (!Q.empty()) {
		int node=Q.front(); Q.pop();
		if (D[node]>0) root=node;
		for (int child : G[node]) {
			if (!vis[child])
				vis[child]=1,
				Q.push(child);
		}
	}

	// for (int i=1; i<=N; i++) if (D[i]>0) root=i;

	vector<int> deg(N+1);
	vector<int> T(N+1);
	vis=vector<int>(N+1);
	Q.push(root);
	vis[root]=1;
	while (!Q.empty()) {
		int node=Q.front(); Q.pop();
		for (int child : G[node]) {
			if (!vis[child])
				vis[child]=1,
				T[child]=node,
				deg[node]++,
				Q.push(child);
		}
	}

	vector<vector<vector<int>>> K(N+1);
	vector<int> keg(N+1);

	for (int i=1; i<=N; i++)
		if (deg[i]==0)
			Q.push(i);
	while (!Q.empty()) {
		int node=Q.front(); Q.pop();
		int next=T[node];
		deg[next]--;

		// hit next;
		if (next) {
			
			if (D[node]<0) {
				// give -D[node] to next
				// cout << node << "->" << next << endl;
				K[node].push_back({next,-(D[node])});
				keg[next]++;
			}
			else if (D[node]>0) {
				// give D[node] from next to node;
				// cout << next << "->" << node << endl;
				K[next].push_back({node,D[node]});
				keg[node]++;
			}
		}
		else break;

		//
		if (deg[next]==0) Q.push(next);
	}
	while (!Q.empty()) Q.pop();

	// traverse K while making answer
	vector<vector<int>> ans;
	for (int i=1; i<=N; i++) if (keg[i]==0) Q.push(i);


	vector<int> DD(N+1);
	while (!Q.empty()) {
		int node=Q.front(); Q.pop();
		for (vector<int> child : K[node]) {
			// cout << node << "->" << child[0] << ": " << child[1] << "+"<<DD[node] << endl;
			ans.push_back({node,child[0],child[1]+DD[node]});
			DD[child[0]]+=DD[node];
			keg[child[0]]--;
			
			if (keg[child[0]]==0) {
				Q.push(child[0]);
			}
		}
	}

	cout << ans.size() << endl;
	for (vector<int> a : ans)
		cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;

}

/*
10
6 6 1 7 8 8 7 1 8 8
1 2
2 3
3 4
4 5
6 7
7 8
8 9
9 10
3 8

vector<int> deg(N+1), vis(N+1), from(N+1);
	for (int i=1; i<=N; i++) {
		deg[i]=G[i].size();
		if (deg[i]==1) Q.push(i), vis[i]=1;
	}
	while (!Q.empty()) {
		int node=Q.front(); Q.pop();

		for (int child : G[node]) {

			if (child!=from[node]) {
				// hit
				cout << "hit: " << node << "->" << child << endl;
			}

			if (!vis[child]) {
				deg[child]--;
				if (deg[child]<=1) {
					vis[child]=1;
					cout << node << "->" << child << endl;
					from[child]=node;
					Q.push(child);
				}
			}
		}
	}
*/