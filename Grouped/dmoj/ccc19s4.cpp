#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

<<<<<<< HEAD
struct Node {
	ll x=0, y=0, sm=0;
};

const int TSZ=1<<20;
ll ar[TSZ], dp[TSZ];
Node tree[TSZ*2];
ll lazy[TSZ*2];

void printNode(Node a) {
	// cout << "(" << a.x << "," << a.xy << ")";
}

void printTree() {
	int i=1;
	for (int sz=1; sz<TSZ*2; sz<<=1) {
		int stop=i+sz;
		for (; i<stop; i++) {
			cout << "(" << tree[i].x << "," << tree[i].y << "," << tree[i].sm << ")" << " ";
		}
		cout << endl;
	}
	// for (int i=0; i<TSZ; i++) cout << "(" << tree[i].x << "," << tree[i].y << "," << tree[i].sm << ")" << " ";  cout << "\n";
	// for (int i=TSZ; i<TSZ*2; i++) cout << "(" << tree[i].x << "," << tree[i].y << "," << tree[i].sm << ")" << " ";  cout << "\n";
	cout << endl;
}

void printLazy() {
	// cout << "lazy: ";
	// for (int i=0; i<TSZ; i++) // cout << lazy[i] << " "; // cout << "| ";
	// for (int i=TSZ; i<TSZ*2; i++) // cout << lazy[i] << " "; // cout << "\n";
	// cout << endl;
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
=======
const int MAXN=1e6;
ll ar[MAXN];
>>>>>>> bf4a286ae018ece9f90054e7bfc406e9865d112d

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
<<<<<<< HEAD
	
	ms(ar,0);
	ms(dp,0);
	ms(tree,0);
	ms(lazy,0);

	int N,K; cin>>N>>K;
	for (int i=1; i<=N; i++) cin>>ar[i];
	
	for (int i=1; i<=N; i++) {
		uptY(1,0,TSZ,0,i,ar[i]);

		// cout << "set [" << 0 << "," << i << ").y->" << ar[i] << endl;
		// printTree();

		int L=max(0,i-K), R=(i-1)/K*K;
		dp[i]=query(1,0,TSZ,L,R+1).sm;
		// cout << "query [" << L << "," << R+1 << "): " << dp[i] << endl;
		// printTree();
		
		uptX(1,0,TSZ,i,dp[i]);

		// cout << "set [" << i << "].x->" << dp[i] << endl;
		// printTree();

		// printTree();
		// // cout << "\t";
		// printLazy();
	}

	// for (int i=1; i<=N; i++) cout << ar[i] << ' '; cout << endl;
	// for (int i=1; i<=N; i++) cout << dp[i] << ' '; cout << endl;
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
=======

	int N,K; cin>>N>>K;
	for (int i=0; i<N; i++) cin>>ar[i];
	
	ll ans=0;
	stack<ll> a,b;
	for (int i=N-1; i>=0; i--) b.push(i==N-1 ? ar[i] : max(b.top(), ar[i]));
	for (int i=0; i<N; i++) {
		a.push(i==0 ? ar[i] : max(a.top(), ar[i])), b.pop();
		if (!SZ(a) || !SZ(b)) continue;
		if (i+1<=K && N-i-1<=K) ans=max(ans,a.top()+b.top());
	}
	if (K==N) ans=*max_element(ar,ar+N);
	cout << ans << endl;

}
>>>>>>> bf4a286ae018ece9f90054e7bfc406e9865d112d
