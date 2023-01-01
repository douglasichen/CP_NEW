#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

struct Node {
	ll sm=0, mxPre=0, mxSuf=0, mxSub=0;
	Node() {}
	Node(int a, int b, int c, int d) {
		sm=a, mxPre=b, mxSuf=c, mxSub=d;
	}
};

const int TSZ=1<<20;
Node UNIT=Node(0,0,0,0);
Node tree[TSZ*2];

Node merge(Node a, Node b) {
	Node ret;
	ret.sm=a.sm+b.sm;
	ret.mxPre=max(a.mxPre, a.sm+b.mxPre);
	ret.mxSuf=max(b.mxSuf, b.sm+a.mxSuf);
	ret.mxSub=max({a.mxSub, b.mxSub, a.mxSuf+b.mxPre});
	return ret;
}

Node upt(int node, int segL, int segR, int pos, int val) {
	if (pos==segL && pos==segR-1) return tree[node]=Node(val,val,val,val);
	if (pos<segL || pos>=segR) return tree[node];
	int mid=segL+segR>>1;
	return tree[node]=merge(upt(node*2, segL, mid, pos, val), upt(node*2+1, mid, segR, pos, val));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q; cin>>N>>Q;
	for (int i=0, val; i<N; i++) cin >> val, tree[i+TSZ]=Node(val, val, val, val);
	for (int i=TSZ-1; i; i--) tree[i]=merge(tree[i<<1], tree[i<<1|1]);

	while (Q--) {
		int A,B; cin>>A>>B;
		upt(1, 0, TSZ, A-1, B);
		cout << max(0LL,tree[1].mxSub) << endl;
	}
}