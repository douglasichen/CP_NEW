#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int TSZ=1<<20;
ll tree[TSZ*2], lazy[TSZ*2];

ll merge(ll a, ll b) {
	return a+b;
}

void down(int node) {
	int left=node*2, right=node*2+1;
	lazy[left]+=lazy[node];
	lazy[right]+=lazy[node];
	tree[left]+=lazy[node];
	tree[right]+=lazy[node];

	lazy[node]=0;
}

ll upt(int node, int segL, int segR, int l, int r, int val) {
	if (r<=segL || l>=segR) return tree[node];
	if (l<=segL && segR<=r) {
		lazy[node]+=val;
		return tree[node]+=val;
	}
	down(node);
	int mid=segL+segR>>1;
	return tree[node]=merge(upt(node*2, segL, mid, l, r, val), upt(node*2+1, mid, segR, l, r, val));
}

ll query(int node, int segL, int segR, int p) {
	if (p<segL || p>=segR) return 0;
	if (p==segL && p==segR-1) return tree[node];
	down(node);
	int mid=segL+segR>>1;
	return merge(query(node*2, segL, mid, p), query(node*2+1, mid, segR, p));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	ms(tree,0);
	ms(lazy,0);

	int N,Q; cin>>N>>Q;
	for (int i=0; i<N; i++) cin>>tree[i+TSZ];
	for (int i=TSZ-1; i; i--) tree[i]=merge(tree[i<<1], tree[i<<1|1]);
	for (int i=0; i<Q; i++) {
		int m, a,b,c; cin>>m>>a; a--;
		if (m==1) {
			cin>>b>>c;
			upt(1,0,TSZ,a,b,c);
		}
		else cout << query(1,0,TSZ,a) << endl;
	}	
}