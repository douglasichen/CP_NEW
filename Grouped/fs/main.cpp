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
	int left=node*2, right=node*2+1;

	if (lazy[1][node]) {
		lazy[1][left]=lazy[1][node];
		lazy[1][right]=lazy[1][node];
		tree[left]=lazy[1][node]*(mid-segL);
		tree[right]=lazy[1][node]*(segR-mid);
		
		lazy[0][left]=0;
		lazy[0][right]=0;
	}
	if (lazy[0][node]) {
		if (lazy[1][left]) lazy[1][left]+=lazy[0][node];
		else lazy[0][left]+=lazy[0][node];
		
		if (lazy[1][right]) lazy[1][right]+=lazy[0][node];
		else lazy[0][right]+=lazy[0][node];

		tree[left]+=lazy[0][node]*(mid-segL);
		tree[right]+=lazy[0][node]*(segR-mid);
	}
	
	lazy[0][node]=0;
	lazy[1][node]=0;
}

// increase
ll upt1(int node, int segL, int segR, int l, int r, ll val) {
	if (r<=segL || l>=segR) return tree[node];
	if (l<=segL && segR<=r) {
		if (lazy[1][node]) lazy[1][node]+=val;
		else lazy[0][node]+=val;
		return tree[node]+=val*(segR-segL);
	}
	int mid=segL+segR>>1;
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
	// for (int i=0; i<TSZ*2; i++) cout << tree[i] << ' ';cout << endl;
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
			printTree();
		}
	}
}

// typo
// logic
// diff

/*
8 12
0 0 0 0 0 0 0 0
2 8 8 6
1 2 4 6
2 5 6 8
1 2 5 9
2 7 8 6
1 2 6 9
2 8 8 7
1 2 7 3
2 5 8 9
1 2 8 10
2 8 8 1
3 4 5
*/