#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int TSZ=1<<20;
ll tree[TSZ*2], lazy[2][TSZ*2];

ll merge(ll a, ll b) {
	return a+b;
}

ll upt(int node, int segL, int segR, int l, int r, int val, int mode) {
	if (r<=segL || l>=segR) return tree[node];
	if (l<=segL && segR<=r) {
		lazy[node]=(mode==0 ? lazy[mode][node]+val : val);
		return tree[node]=(mode==1 ? tree[node]+val : val);
	}
	pushDown
	int mid=segL+segR;
	return merge(upt(node*2, segL, mid, l, r, val, mode), upt(node*2+1, mid, segR, l, r, val, mode));
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
			upt(1, 0, TSZ, a, b, x, m-1);
		}
	}
}