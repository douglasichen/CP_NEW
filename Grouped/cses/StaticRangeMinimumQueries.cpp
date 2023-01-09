#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int TSZ=1<<20;
int tree[TSZ*2];

int merge(int a, int b) {
	return min(a,b);
}
int query(int node, int segL, int segR, int l, int r) {
	if (r<=segL || l>=segR) return INT_MAX;
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
		int a,b; cin>>a>>b; a--;
		cout << query(1,0,TSZ,a,b) << endl;
	}
}