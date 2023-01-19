#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

struct Node {
	ll x=0, xy=0;
};

const int TSZ=1<<20;
ll ar[TSZ], dp[TSZ];
Node tree[TSZ*2];
ll lazy[TSZ*2];

Node merge(Node a, Node b) {
	return {max(a.x, b.x), max(a.xy, b.xy)};
}

void down(int node) {
	int left=node*2, right=node*2+1;
	if (lazy[node]) {
		lazy[left]=lazy[node];
		lazy[right]=lazy[node];
		tree[left].xy=max(tree[left].xy, tree[left].x+lazy[node]);
		tree[right].xy=max(tree[right].xy, tree[right].x+lazy[node]);
	}
	lazy[node]=0;
}

void uptY(ll y) {
	tree[1].xy=max(tree[1].xy, tree[1].x+y);
	lazy[1]=y;
}

Node uptX(int node, int segL, int segR, int pos, int val) {
	if (pos<segL || pos>=segR) return tree[node];
	if (pos==segL && pos==segR-1) {
		tree[node].x=val;
		return tree[node];
	}
	down(node);
	int mid=segL+segR>>1;
	return tree[node]=merge(uptX(node*2, segL, mid, pos, val), uptX(node*2+1, mid, segR, pos, val));
}

Node query(int node, int segL, int segR, int l, int r) {
	if (r<=segL || l>=segR) return {0,0};
	if (l<=segL && segR<=r) return tree[node];
	down(node);
	int mid=segL+segR>>1;
	return merge(query(node*2, segL, mid, l, r), query(node*2+1, mid, segR, l, r));
}


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	ms(ar,0);
	ms(dp,0);
	ms(tree,0);
	ms(lazy,0);

	int N,K; cin>>N>>K;
	for (int i=1; i<=N; i++) cin>>ar[i];
	
	for (int i=1; i<=N; i++) {
		uptY(ar[i]);

		int L=max(0,i-K), R=(i-1)/K*K;
		dp[i]=query(1,0,TSZ,L,R+1).xy;
		uptX(1,0,TSZ,i,dp[i]);
	}
	cout << dp[N] << endl;
}

/*
9 7
8 4 4 5 1 2 2 4 9 

*/