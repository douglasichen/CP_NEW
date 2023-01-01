#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int M, mxv=800;
vector<vector<int>> edges; // a, b, cost

vector<int> dsu;

int root(int a) {
	return dsu[a]<0 ? a : dsu[a]=root(dsu[a]);
}

void join(int a, int b) {
	a=root(a), b=root(b);
	if (a==b) return;
	if (-dsu[a]<-dsu[b]) swap(a,b);
	dsu[a]+=dsu[b];
	dsu[b]=a;	
}


int mst() {
	dsu=vector<int>(101,-1); // size M

	int ans=0;
	sort(edges.begin(), edges.end());
	for (vector<int> e : edges) {
		int a=e[1], b=e[2], cost=e[0];
		if (root(a)==root(b)) continue;
		join(a,b);
		ans+=cost;
	}

	int rt=root(0);
	for (int i=1; i<M; i++) {
		if (root(i)!=rt) {
			ans=INT_MAX;
			break;
		}
	}
	return ans;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>M;
	vector<vector<pair<vector<int>,int>>> mat(mxv+1, vector<pair<vector<int>,int>>(mxv+1));
	for (int i=0,E; i<M; i++) {
		cin>>E;
		vector<int> V(E+1);
		for (int e=0; e<E; e++) cin>>V[e];
		V[E]=V[0];

		for (int e=0,a,b,cost; e<E; e++) {
			a=V[e], b=V[e+1];
			if (a>b) swap(a,b);
			cin>>cost;
			mat[a][b].first.push_back(i);
			mat[a][b].second=cost;
		}
	}
	for (int a=1; a<=mxv; a++)
		for (int b=a+1; b<=mxv; b++)
			if (mat[a][b].first.size()==2)
				edges.push_back({mat[a][b].second, mat[a][b].first[0], mat[a][b].first[1]});
	
	int ans=mst();
	for (int a=1; a<=mxv; a++)
		for (int b=a+1; b<=mxv; b++)
			if (mat[a][b].first.size()==1)
				edges.push_back({mat[a][b].second, M, mat[a][b].first[0]});
	
	ans=min(ans,mst());
	cout << ans << endl;
}