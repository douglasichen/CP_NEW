#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int TSZ=1<<20;
const ll UNIT = -1e18;
ll tree[TSZ*2], ar[TSZ], lazy[TSZ*2];

void printTree() {
	for (int i=0; i<TSZ*2; i++) cout << tree[i] << ' '; cout << endl;
}

ll merge(ll a, ll b) {
	return max(a,b);
}

void pushDown(int node) {
	tree[node*2]+=lazy[node];
	tree[node*2+1]+=lazy[node];
	lazy[node*2]+=lazy[node];
	lazy[node*2+1]+=lazy[node];
	lazy[node]=0;
}

ll upt(int node, int segL, int segR, int L, int R, int val) {
	if (R<=segL || L>=segR) return tree[node];
	if (L<=segL && segR<=R) {
		lazy[node]+=val;
		return tree[node]+=val;
	}
	pushDown(node);
	
	int mid=segL+segR>>1;
	return tree[node]=merge(upt(node*2, segL, mid, L, R, val), 
							upt(node*2+1, mid, segR, L, R, val));
}


ll query(int node, int segL, int segR, int L, int R) {
	if (R<=segL || L>=segR) return UNIT;
	if (L<=segL && segR<=R) return tree[node];
	pushDown(node);

	int mid=segL+segR>>1;
	return merge(query(node*2, segL, mid, L, R), query(node*2+1, mid, segR, L, R));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	memset(tree, 0, sizeof(tree));
	memset(ar, 0, sizeof(ar));
	memset(lazy, 0, sizeof(lazy));

	int N,Q; cin >> N >> Q;
	for (int i=1; i<=N; i++) cin>>ar[i], tree[i+TSZ]=ar[i]+tree[i+TSZ-1];
	for (int i=TSZ-1; i; i--) tree[i]=merge(tree[i<<1], tree[i<<1|1]);

	while (Q--) {
		int X, A, B; cin >> X >> A >> B;
		if (X==1) upt(1, 0, TSZ, A, N+1, B-ar[A]), ar[A]=B;
		else {
			cout << max(0LL, query(1, 0, TSZ, A, B+1)-query(1, 0, TSZ, A-1, A)) << endl;
		}
	}
}