#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

struct Node {
	ll x=0, y=0, xy=0;
};

const int TSZ=1<<3;
ll ar[TSZ], dp[TSZ];
Node tree[TSZ*2];
ll lazy[TSZ*2];

void printNode(Node a) {
	// cout << "(" << a.x << "," << a.xy << ")";
}

Node merge(Node a, Node b, int y) {
	// printNode(a), printNode(b), // cout << " -> ", printNode({max(a.x, b.x), max(a.xy, b.xy)});
	// cout << endl;
	return {max(a.x, b.x), y, max({a.xy, b.xy, max(a.x, b.x)+y})};
}

void printTree() {
	cout << "tree: ";
	for (int i=0; i<TSZ; i++) cout << tree[i].x << " ";  cout << "| ";
	for (int i=TSZ; i<TSZ*2; i++) cout << tree[i].x << " ";  cout << "\n";
	cout << endl;
}

void printLazy() {
	// cout << "lazy: ";
	// for (int i=0; i<TSZ; i++) // cout << lazy[i] << " "; // cout << "| ";
	// for (int i=TSZ; i<TSZ*2; i++) // cout << lazy[i] << " "; // cout << "\n";
	// cout << endl;
}

void down(int node) {
	int left=node*2, right=node*2+1;
	if (lazy[node]>tree[left].y) {
		lazy[left]=lazy[node];
		tree[left].y=lazy[node];
		tree[left].xy=tree[left].x+lazy[node];
	}
	if (lazy[node]>tree[right].y) {
		lazy[right]=lazy[node];
		tree[right].y=lazy[node];
		tree[right].xy=tree[right].x+lazy[node];
	}
	lazy[node]=0;
}

Node uptY(int node, int segL, int segR, int l, int r, ll val) {
	if (r<=segL || l>=segR) return tree[node];
	if (l<=segL && segR<=r) {
		if (val>tree[node].y) {
			lazy[node]=val;
			tree[node].y=val;
			tree[node].xy=tree[node].x+val;
		}
		return tree[node];
	}
	down(node);
	int mid=segL+segR>>1;
	return tree[node]=merge(uptY(node*2, segL, mid, l, r, val), uptY(node*2+1, mid, segR, l, r, val), tree[node].y);
}

Node uptX(int node, int segL, int segR, int pos, int val) {
	if (pos<segL || pos>=segR) return tree[node];
	if (pos==segL && pos==segR-1) {
		tree[node].x=val;
		tree[node].xy=val;
		return tree[node];
	}
	down(node);
	int mid=segL+segR>>1;
	return tree[node]=merge(uptX(node*2, segL, mid, pos, val), uptX(node*2+1, mid, segR, pos, val), tree[node].y);
}

Node query(int node, int segL, int segR, int l, int r) {
	if (r<=segL || l>=segR) return {0,0};
	if (l<=segL && segR<=r) return tree[node];
	down(node);
	int mid=segL+segR>>1;
	// cout << "at: " << node << endl;
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
		uptY(1,0,TSZ,0,i,ar[i]);

		int L=max(0,i-K), R=(i-1)/K*K;

		Node ans=query(1,0,TSZ,L,R+1);
		// cout << ans.x << ' ' << ans.y << ' ' << ans.xy << endl;

		dp[i]=query(1,0,TSZ,L,R+1).xy;
		uptX(1,0,TSZ,i,dp[i]);

		// for (int o=1; o<TSZ; o++) down(o);
		// cout << L << " " << R << endl;

		printTree();
		// // cout << "\t";
		// printLazy();
	}
	for (int i=1; i<=N; i++) cout << dp[i] << ' '; cout << endl;
	cout << dp[N] << endl;
}

/*
input:
7 4
6 4 8 9 3 2 4 

wanted output:
6 6 8 9 17 17 17
17

input: 
6 3
4 6 6 4 3 1 

wanted output:
10

*/