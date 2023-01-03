#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int TSZ=1<<17;
ll tree[TSZ*2], lazy[TSZ*2][2], INF=1e11;

ll merge(ll a, ll b) {
	return min(a,b);
}

void pushDown(int node) {
	int left=node*2, right=node*2+1;
	if (lazy[node][0]) {
		if (lazy[left][1]) lazy[left][1]+=lazy[node][0];
		else lazy[left][0]+=lazy[node][0];

		if (lazy[right][1]) lazy[right][1]+=lazy[node][0];
		else lazy[right][0]+=lazy[node][0];

		tree[left]+=lazy[node][0];
		tree[right]+=lazy[node][0];
	}

	if (lazy[node][1]) {
		lazy[left][1]=lazy[node][1];
		lazy[right][1]=lazy[node][1];
		
		lazy[left][0]=0;
		lazy[right][0]=0;

		tree[left]=lazy[node][1];
		tree[right]=lazy[node][1];
	}

	lazy[node][0]=0;
	lazy[node][1]=0;
}

ll upt(int node, int segL, int segR, int l, int r, ll val, int m) {
	if (r<=segL || l>=segR) return tree[node];
	if (l<=segL && segR<=r) {
		if (m==1) {
			if (lazy[node][1]) lazy[node][1]+=val;
			else lazy[node][0]+=val;
			return tree[node]+=val;
		}
		else {
			lazy[node][1]=val;
			lazy[node][0]=0;
			return tree[node]=val;
		}
	}

	pushDown(node);
	int mid=segL+segR>>1;
	return tree[node]=merge(upt(node*2, segL, mid, l, r, val, m), upt(node*2+1, mid, segR, l, r, val, m));
}

ll query(int node, int segL, int segR, int l, int r) {
	if (r<=segL || l>=segR) return INF;
	if (l<=segL && segR<=r) return tree[node];
	
	pushDown(node);
	int mid=segL+segR>>1;
	return merge(query(node*2, segL, mid, l, r), query(node*2+1, mid, segR, l, r));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	memset(tree, 0, sizeof(tree));
	memset(lazy, 0, sizeof(lazy));

	int N,Q; cin>>N>>Q;
	for (int i=0; i<N; i++) cin>>tree[i+TSZ];
	for (int i=TSZ-1; i; i--) tree[i]=merge(tree[i<<1], tree[i<<1|1]);

	while (Q--) {
		int m, a, b; cin>>m>>a>>b; a--;
		if (m==3) {
			cout << query(1, 0, TSZ, a, b) << endl;
		}
		else {
			int x; cin>>x;
			if (m==1) upt(1, 0, TSZ, a, b, x, m);
			else upt(1, 0, TSZ, a, b, x, m);
		}
	}
}