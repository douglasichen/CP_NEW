#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAX_N=1e5+1, MAX_M=2e5+1, E=19;
int ord[MAX_M], dsu[MAX_N], anc[E][MAX_N], mx[E][MAX_N], lev[MAX_N], on[MAX_M], mstUse[MAX_M];
int N, M, D;
vector<ll> edges[MAX_M];
vector<vector<ll>> mst[MAX_N];

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

bool comp(vector<ll> a, vector<ll> b) {
	if (a[0]<b[0]) return 1;
	if (a[0]==b[0] && a[1]<b[1]) return 1;
	return 0;
}

int bigger(int a, int b) {
	if (edges[a][0]==edges[b][0]) return (on[a]<on[b] ? a : b);
	return (edges[a][0]>edges[b][0] ? a : b);
}

int getLca(int a, int b) {
	if (lev[a]<lev[b]) swap(a,b);
	for (int e=E-1; e>=0; e--) if (lev[anc[e][a]]>=lev[b]) a=anc[e][a];
	for (int e=E-1; e>=0; e--) if (anc[e][a]!=anc[e][b]) a=anc[e][a], b=anc[e][b];
	return (a==b ? a : anc[0][a]);
}

int getMaxEdge(int a, int b) {
	int lca=getLca(a,b), res=M;
	for (int e=E-1; e>=0; e--) {
		if (lev[anc[e][a]]>=lev[lca]) {
			res=bigger(mx[e][a], res);
			a=anc[e][a];
		}
	}
	for (int e=E-1; e>=0; e--) {
		if (lev[anc[e][b]]>=lev[lca]) {
			res=bigger(mx[e][b], res);
			b=anc[e][b];
		}
	}
	return res;
}

void build(int node, int from, int fromEdge, int l) {
	anc[0][node]=from;
	mx[0][node]=fromEdge;
	lev[node]=l;
	for (int e=1; e<E; e++) {
		anc[e][node]=anc[e-1][anc[e-1][node]];
		mx[e][node]=bigger(mx[e-1][node], mx[e-1][anc[e-1][node]]);
	}
	for (vector<ll> child : mst[node]) if (child[1]!=from) build(child[1], node, child[2], l+1);
}

void printAnc() {
	cout << "anc:" << endl;
	for (int e=0; e<=3; e++) {
		cout << e << ": ";
		for (int i=1; i<=N; i++) {
			cout << anc[e][i] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void printMst() {
	vector<vector<ll>> ed;
	queue<ll> qu;
	vector<bool> vis(N+1);
	qu.push(1);
	vis[1]=1;
	while (SZ(qu)) {
		int node=qu.front(); qu.pop();
		for (vector<ll> child : mst[node]) {
			if (!vis[child[1]]) {
				vis[child[1]]=1;
				qu.push(child[1]);
				ed.push_back({node,child[1],child[0]});
			}
		}
	}
	for (vector<ll> e : ed) {
		cout << e[0] << ' ' << e[1] << ' ' << e[2] << endl;
	}
} 

void printMx() {
	cout << "mx:" << endl;
	for (int e=0; e<=3; e++) {
		for (int i=1; i<=N; i++) {
			cout << mx[e][i] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(on,0);
	ms(mstUse,0);
	fill(dsu,dsu+MAX_N,-1);

	cin>>N>>M>>D;
	edges[M]={0,0,0,0};
	for (int i=0; i<M; i++) {
		if (i<N-1) on[i]=1;
		int a,b,c; cin>>a>>b>>c;
		edges[i]={c,-on[i],a,b};
	}
	iota(ord, ord+M, 0);
	sort(ord, ord+M, [&](int a, int b) {return comp(edges[a], edges[b]); });

	ll mstCost=0;
	for (int o=0; o<M; o++) {
		int i=ord[o];
		if (unite(edges[i][2], edges[i][3])) {
			mstCost+=edges[i][0];
			mstUse[i]=1;

			mst[edges[i][2]].push_back({edges[i][0], edges[i][3], i});
			mst[edges[i][3]].push_back({edges[i][0], edges[i][2], i});
		}
	}

	build(1, 1, M, 0);
	// printAnc();
	// printMx();
	// printMst();

	vector<ll> best={mstCost, 0, M, M}; // treeCost, change, edge, remEdge.
	for (int i=0; i<M; i++) {
		if (mstUse[i]) {
			vector<ll> nw={mstCost-edges[i][0]+max(edges[i][0]-D, 0LL), 0LL, i, M};
			if (comp(nw,best)) best=nw;
		}
		else {
			int mxEdge=getMaxEdge(edges[i][2], edges[i][3]);
			ll cost=mstCost-edges[mxEdge][0]+max(0LL, edges[i][0]-D);
			vector<ll> nw={cost, on[mxEdge]-on[i], i, mxEdge};
			if (comp(nw,best)) best=nw;
		}
	}
	mstUse[best[2]]=1;
	mstUse[best[3]]=0;

	ll ans=0;
	for (int i=0; i<M; i++) ans+=(on[i]^mstUse[i]);
	cout << (ans+1)/2 << endl;
}

/*
10 18 2
2 1 2
3 1 1
4 3 2
5 3 1
6 1 1
7 2 1
8 1 1
9 1 1
10 6 1
2 1 1
3 1 2
4 3 2
5 2 2
6 1 2
7 6 1
8 4 1
9 7 2
10 4 1
*/
