#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=2e5+1;
vector<int> edges[MAXN], flat;
vector<vector<int>> gr[MAXN], mst[MAXN];
int dsu[MAXN], ord[MAXN], on[MAXN], from[MAXN], fromCost[MAXN], sz[MAXN], mstUse[MAXN], node2flat[MAXN];

int root(int a) {
	return dsu[a]<0 ? a : dsu[a]=root(dsu[a]);
}

bool unite(int a, int b) {
	a=root(a), b=root(b);
	if (a==b) return 0;
	if (dsu[a]>dsu[b]) swap(a,b);
	dsu[a]+=dsu[b];
	dsu[b]=a;
	return 1;
}


// create from array, create flattened array, create sz array

int dfs(int node) {
	node2flat[node]=SZ(flat);
	flat.push_back(node);
	
	sz[node]=1;
	for (vector<int> child : mst[node]) {
		if (child[1]!=from[node]) {
			from[child[1]]=node;
			fromCost[child[1]]=child[0];
			sz[node]+=dfs(child[1]);
		}
	}
	return sz[node];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(on,0);
	ms(from,0);
	ms(fromCost,0);
	ms(sz,0);
	ms(mstUse,0);

	iota(ord,ord+MAXN,0);
	fill(dsu,dsu+MAXN,-1);

	int N,M,D; cin>>N>>M>>D;
	for (int i=0; i<M; i++) {
		if (i<N-1) on[i]=1;
		int a,b,c; cin>>a>>b>>c;
		edges[i]={c,a,b};
		
		gr[a].push_back({c,b});
		gr[b].push_back({c,a});
	}
	sort(ord,ord+M,[&](int a, int b) {
		if (edges[a][0]==edges[b][0]) return on[a]>on[b];
		return edges[a][0]<edges[b][0];
	});

	ll mstCost=0;
	for (int o=0; o<M; o++) {
		int i=ord[o];
		if (unite(edges[i][1], edges[i][2])) {
			// on[i]^=1;
			mst[edges[i][1]].push_back({edges[i][0], edges[i][2]});
			mst[edges[i][2]].push_back({edges[i][0], edges[i][1]});
			mstUse[i]=1;
			mstCost+=edges[i][0];
		}
	}

	dfs(1);
	
	ll mnCost=mstCost, nCost, x, y;
	int best=-1;
	vector<int> off, bestOff;
	for (int i=0; i<M; i++) {
		// if i take this edge away and replace with max(0,cost-D), what is the total cost now?
		vector<int> e=edges[i];
		if (mstUse[i]) {
			nCost=mstCost-e[0]+max(0, e[0]-D);
			if (nCost<mnCost) {
				mnCost=nCost;
			}
		}
		else {
			// check if a is child of b and other way
			int l=node2flat[e[1]], r=l+sz[e[1]], at=node2flat[e[2]];
			if (at<l || at>=r) swap(e[1], e[2]);

			l=node2flat[e[1]], r=l+sz[e[1]], at=node2flat[e[2]];
			if (l<=at && at<r) {
				// find what branch it is in
				for (vector<int> child : mst[e[1]]) {
					int node=child[1];
					if (node!=from[e[1]]) {
						l=node2flat[node], r=l+sz[node];
						if (l<=at && at<r) {
							// found;
							x=child[0];
							off={e[1], node};
							break;
						}
					}
				}

				y=fromCost[e[2]];

				if (y>x) off={from[e[2]], e[2]};
			}
			else {
				x=fromCost[e[1]];
				y=fromCost[e[2]];

				off=(x>y ? {from[e[1]], e[1]} : {from[e[2]], e[2]});
			}

		
			nCost=mstCost-max(x,y)+max(0, e[0]-D);
			if (nCost<mnCost) {
				mnCost=nCost;
				best=i;
				bestOff=off;
			}
		}
	}

	if (best==-1) {
		for (int i=0; i<M; i++) {
			if (mstUsed[i]) {
				on[i]^=1;
			}
		}
	}
	else {

	}
}