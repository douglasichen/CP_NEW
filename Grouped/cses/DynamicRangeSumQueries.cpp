#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int TSZ=1<<20;
ll tree[TSZ*2];

ll merge(ll a, ll b) {
	return a+b;
}

ll upt(int node, int segL, int segR, int pos, int val) {
	if (pos<segL || pos>=segR) return tree[node];
	if (pos==segL && pos==segR-1) return tree[node]=val;
	int mid=segL+segR>>1;
	return tree[node]=merge(upt(node*2, segL, mid, pos, val), upt(node*2+1, mid, segR, pos, val));
}

ll query(int node, int segL, int segR, int l, int r) {
	if (r<=segL || l>=segR) return 0;
	if (l<=segL && segR<=r) return tree[node];
	int mid=segL+segR>>1;
	return merge(query(node*2, segL, mid, l, r), query(node*2+1, mid, segR, l, r));
}


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q; cin>>N>>Q;
	for (int i=0; i<N; i++) cin>>tree[i+TSZ];
	for (int i=TSZ-1; i; i--) tree[i]=merge(tree[i<<1], tree[i<<1|1]);
	for (int i=0; i<Q; i++) {
		int m,a,b; cin>>m>>a>>b; a--;
		if (m==1) {
			upt(1,0,TSZ,a,b);
		}
		else cout << query(1,0,TSZ,a,b) << endl;
	}
}