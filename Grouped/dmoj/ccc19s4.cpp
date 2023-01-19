#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

struct Node {
	ll x=0, y=0, sm=0;
};

const int TSZ=1<<20;
ll ar[TSZ], dp[TSZ], lazy[TSZ*2];
Node tree[TSZ*2];

void printTree() {
	int i=1;
	for (int sz=1; sz<TSZ*2; sz<<=1) {
		int stop=i+sz;
		for (; i<stop; i++) {
			cout << "(" << tree[i].x << "," << tree[i].y << "," << tree[i].sm << ")" << " ";
		}
		cout << endl;
	}
	cout << endl;
}

Node merge(Node a, Node b, int y) {
	Node res={max(a.x, b.x), y, 0};
	res.sm=max({a.sm, b.sm});
	return res;
}

void down(int node) {
	int left=node*2, right=node*2+1;
	if (lazy[node]) {
		if (lazy[node]>tree[left].y) {
			lazy[left]=lazy[node];
			tree[left].y=lazy[node];
			tree[left].sm=max(tree[left].sm, tree[left].x+tree[left].y);
		}
		if (lazy[node]>tree[right].y) {
			lazy[right]=lazy[node];
			tree[right].y=lazy[node];
			tree[right].sm=max(tree[right].sm, tree[right].x+tree[right].y);
		}
	}
	lazy[node]=0;
}

Node uptY(int node, int segL, int segR, int l, int r, ll val) {
	if (r<=segL || l>=segR) return tree[node];
	if (l<=segL && segR<=r) {
		if (val>tree[node].y) {
			lazy[node]=val;
			tree[node].y=val;
			tree[node].sm=max(tree[node].sm, tree[node].x+tree[node].y);
		}
		return tree[node];
	}
	down(node);
	int mid=segL+segR>>1;
	return tree[node]=merge(uptY(node*2, segL, mid, l, r, val), uptY(node*2+1, mid, segR, l, r, val), tree[node].y);
}

Node uptX(int node, int segL, int segR, int pos, ll val) {
	if (pos<segL || pos>=segR) return tree[node];
	if (pos==segL && pos==segR-1) {
		tree[node].x=val;
		tree[node].sm=tree[node].x+tree[node].y;
		return tree[node];
	}
	down(node);
	int mid=segL+segR>>1;
	return tree[node]=merge(uptX(node*2, segL, mid, pos, val), uptX(node*2+1, mid, segR, pos, val), tree[node].y);
}


Node query(int node, int segL, int segR, int l, int r) {
	if (r<=segL || l>=segR) return {0,0,0};
	if (l<=segL && segR<=r) return tree[node];
	down(node);
	int mid=segL+segR>>1;
	return merge(query(node*2, segL, mid, l, r), query(node*2+1, mid, segR, l, r), tree[node].y);
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
		int L=max(0,i-K), R=(i-1)/K*K;
		uptY(1,0,TSZ,0,i,ar[i]);
		dp[i]=query(1,0,TSZ,L,R+1).sm;
		uptX(1,0,TSZ,i,dp[i]);
	}
	cout << dp[N] << endl;
}