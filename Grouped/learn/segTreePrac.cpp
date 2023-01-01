#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int SZ=1<<20;
ll tree[SZ*2], lazy[SZ*2];
int N,Q;

ll merge(ll a, ll b) {
	return a+b;
}

void pushDown(int node) {
	tree[node*2]+=lazy[node];
	tree[node*2+1]+=lazy[node];
	lazy[node*2]+=lazy[node];
	lazy[node*2+1]+=lazy[node];
	lazy[node]=0;
}

ll query(int node, int segL, int segR, int pos) {
	if (pos<segL || pos>=segR) return 0;
	if (segL==pos && segR-1==pos) return tree[node];
	pushDown(node);
	int mid=segL+segR>>1;
	return merge(query(node*2, segL, mid, pos), query(node*2+1, mid, segR, pos));
}

ll modify(int node, int segL, int segR, int L, int R, int val) {
	if (R<=segL || L>=segR) return tree[node];
	if (L<=segL && segR<=R) {
		lazy[node]+=val;
		return tree[node]+=val;
	}
	pushDown(node);
	int mid=segL+segR>>1;
	return tree[node]=merge(modify(node*2, segL, mid, L, R, val), 
							modify(node*2+1, mid, segR, L, R, val));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	memset(tree, 0, sizeof(tree));
	memset(lazy, 0, sizeof(lazy));

	cin>>N>>Q;
	for (int i=0; i<N; i++) cin>>tree[i+SZ];
	for (int i=SZ-1; i; i--) tree[i]=merge(tree[i<<1], tree[i<<1|1]);

	while (Q--) {
		int X; cin>>X;
		if (X==1) {
			// range increase
			int A,B,U; cin>>A>>B>>U; A--;
			modify(1, 0, SZ, A, B, U);
		}
		else {
			// query value at position
			int P; cin>>P; P--;
			cout << query(1, 0, SZ, P) << endl;
		}
	}
}