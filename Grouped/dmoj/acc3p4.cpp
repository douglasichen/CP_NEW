#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

struct Eq {
	ll m,b;
};

const int TSZ=1<<20;
ll tree[TSZ*2];
Eq lazy[TSZ*2];

ll merge(ll a, ll b) {
	return a+b;
}

Eq eqAdd(Eq a, Eq b) {
	return {a.m+b.m, a.b+b.b};
}

ll area(Eq eq, int l, int r) {
	ll len=r-l;
	return len*(len-1)/2*eq.m + eq.b*len;
}

Eq shiftEq(Eq eq, ll x) {
	return {eq.m, eq.m*x+eq.b};
}

void pushDown(int node, int segL, int mid, int segR) {
	int left=node*2, right=node*2+1;
	Eq eqL=lazy[node], eqR=shiftEq(lazy[node], mid-segL);

	lazy[left]=eqAdd(lazy[left], eqL);
	lazy[right]=eqAdd(lazy[right], eqR);

	tree[left]+=area(eqL, segL, mid);
	tree[right]+=area(eqR, mid, segR);

	lazy[node]={0,0};
}

ll upt(int node, int segL, int segR, int l, int r, Eq eq) {
	if (r<=segL || l>=segR) return tree[node];
	if (l<=segL && segR<=r) {
		lazy[node]=eqAdd(lazy[node], eq);
		// cout << "area of " << eq.m << " " << eq.b << " from " << segL << " " << segR << " is " << area(eq, segL, segR) << endl;
		return tree[node]+=area(eq, segL, segR);
	}
	
	int mid=segL+segR>>1;
	pushDown(node, segL, mid, segR);


	// left segment
	Eq eqL=eq, eqR=eq;
	if (l<=segL && mid<=r) eqL=shiftEq(eq, segL-l);
	if (l<=mid && segR<=r) eqR=shiftEq(eq, mid-l);
	return tree[node]=merge(upt(node*2, segL, mid, l, r, eqL), upt(node*2+1, mid, segR, l, r, eqR));
}

ll query(int node, int segL, int segR, int l, int r) {
	if (r<=segL || l>=segR) return 0;
	if (l<=segL && segR<=r) return tree[node];
	
	int mid=segL+segR>>1;
	pushDown(node, segL, mid, segR);
	return merge(query(node*2, segL, mid, l, r), query(node*2+1, mid, segR, l, r));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	memset(tree, 0, sizeof(tree));

	int N, Q; cin>>N>>Q;
	while (Q--) {
		int mode, l, r, a; cin>>mode>>l>>r; l--;
		if (mode==1) {
		    int a; cin>>a;
		    upt(1, 0, TSZ, l, r, {a,a});
		}
		else cout << query(1, 0, TSZ, l, r) << endl;
	}
}