#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int TSZ=1<<20;
ll tree[TSZ*2], lazy[2][TSZ*2];

ll merge(ll a, ll b) {
	return a+b;
}

void pushDown(int node, int segL, int mid, int segR) {
	if (lazy[0][node]) {
		lazy[0][node*2]+=lazy[0][node];
		lazy[0][node*2+1]+=lazy[0][node];
		tree[node*2]+=lazy[0][node]*(mid-segL);
		tree[node*2+1]+=lazy[0][node]*(segR-mid);

		lazy[1][node*2]=0;
		lazy[1][node*2+1]=0;
	}
	if (lazy[1][node]) {
		lazy[1][node*2]=lazy[1][node];
		lazy[1][node*2+1]=lazy[1][node];
		tree[node*2]=lazy[1][node]*(mid-segL);
		tree[node*2+1]=lazy[1][node]*(segR-mid);
		
		lazy[0][node*2]=0;
		lazy[0][node*2+1]=0;
	}
	
	lazy[0][node]=0;
	lazy[1][node]=0;
}

// increase
ll upt1(int node, int segL, int segR, int l, int r, ll val) {
	if (r<=segL || l>=segR) return tree[node];
	
	int mid=segL+segR>>1;
	if (l<=segL && segR<=r) {
		if (node<TSZ) pushDown(node, segL, mid, segR);
		lazy[0][node]+=val;
		return tree[node]+=val*(segR-segL);
	}
	pushDown(node, segL, mid, segR);
	return tree[node]=merge(upt1(node*2, segL, mid, l, r, val), upt1(node*2+1, mid, segR, l, r, val));
}

ll upt2(int node, int segL, int segR, int l, int r, ll val) {
	if (r<=segL || l>=segR) return tree[node];
	if (l<=segL && segR<=r) {
		lazy[1][node]=val;
		lazy[0][node]=0;
		return tree[node]=val*(segR-segL);
	}

	int mid=segL+segR>>1;
	pushDown(node, segL, mid, segR);
	return tree[node]=merge(upt2(node*2, segL, mid, l, r, val), upt2(node*2+1, mid, segR, l, r, val));
}

void printTree() {
	for (int i=0; i<TSZ*2; i++) cout << tree[i] << ' ';cout << endl;
}

ll query(int node, int segL, int segR, int l, int r) {
	if (r<=segL || l>=segR) return 0;
	if (l<=segL && segR<=r) return tree[node];
	
	int mid=segL+segR>>1;
	pushDown(node, segL, mid, segR);
	return merge(query(node*2, segL, mid, l, r), query(node*2+1, mid, segR, l, r));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	memset(tree, 0, sizeof(tree));
	memset(lazy, 0, sizeof(lazy));

	int N, Q; cin>>N>>Q;
	for (int i=0; i<N; i++) cin>>tree[i+TSZ];
	for (int i=TSZ-1; i; i--) tree[i]=merge(tree[i<<1], tree[i<<1|1]);

	while (Q--) {
		int m, a, b; cin>>m>>a>>b; a--;
		if (m==3) {
			cout << query(1, 0, TSZ, a, b) << endl;
		}
		else {
			int x; cin>>x;
			if (m==1) upt1(1, 0, TSZ, a, b, x);
			else upt2(1, 0, TSZ, a, b, x);
		}
	}
}

// typo
// logic
// diff