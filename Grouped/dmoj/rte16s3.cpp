#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int E=18, MAXN=6000;
int anc[E][MAXN], lvl[MAXN];
ll dist[MAXN];
vector<vector<int>> tree[MAXN];



void build(int node, int from, int l) {
	lvl[node]=l;
	anc[0][node]=from;

	for (int e=1; e<E; e++) anc[e][node]=anc[e-1][anc[e-1][node]];
	for (vector<int> child : tree[node])
		if (child[0]!=from)
			build(child[0], node, l+1);
}

void disTrav(int node, int from, ll d) {
	dist[node]=d;
	for (vector<int> child : tree[node]) 
		if (child[0]!=from) 
			disTrav(child[0], node, d+child[1]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(anc,0);
	ms(lvl,0);
	ms(dist,0);

	int N; cin>>N;
	for (int i=0; i<N-1; i++) {
		int a,b,w; cin>>a>>b>>w;
		tree[a].push_back({b,w});
		tree[b].push_back({a,w});
	}

	build(0,0,0);
	disTrav(0,0,0);
	
	int Q; cin>>Q;
	while (Q--) {
		int A,B,a,b; cin>>A>>B;
		a=A, b=B;
		
		if (lvl[a]<lvl[b]) swap(a,b);
		for (int e=E-1; e>=0; e--)
			if (lvl[anc[e][a]]>=lvl[b])
				a=anc[e][a];
		
		int c=0;
		for (int e=E-1; e>=0; e--)
			if (anc[e][a]!=anc[e][b])
				a=anc[e][a],
				b=anc[e][b];
		if (a==b) c=a;
		else c=anc[0][a];

		cout << dist[A]+dist[B]-dist[c]*2 << endl;
	}


}

/*
10
0 1 1
1 2 2
1 3 3
2 7 2
2 4 2
2 5 2
3 6 3
7 8 2
7 9 2

*/