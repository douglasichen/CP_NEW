#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int TSZ=1<<20;
ll tree[TSZ*2], lazy[TSZ*2], qs[TSZ][3];

ll gcd(ll a, ll b) {
	while (b) {
		a%=b;
		swap(a,b);
	}
	return a;
}

ll lcm(ll a, ll b) {
	if (!a || !b) return max(a,b);
	return a/gcd(a,b)*b;
}

ll merge(ll a, ll b) {
	return gcd(a,b);
}

void pushDown(int node) {
	int left=node*2, right=node*2+1;
	lazy[left]=lcm(lazy[left], lazy[node]);
	lazy[right]=lcm(lazy[right], lazy[node]);

	tree[left]=lcm(tree[left], lazy[node]);
	tree[right]=lcm(tree[right], lazy[node]);

	lazy[node]=1;
}

ll upt(int node, int segL, int segR, int l, int r, int val) {
	if (r<=segL || l>=segR) return tree[node];
	if (l<=segL && segR<=r) {
		lazy[node]=lcm(lazy[node], val);
		return tree[node]=lcm(tree[node], val);
	}
	pushDown(node);
	int mid=segL+segR>>1;
	return tree[node]=merge(upt(node*2, segL, mid, l, r, val), upt(node*2+1, mid, segR, l, r, val));
}

ll query(int node, int segL, int segR, int l, int r)  {
	if (r<=segL || l>=segR) return 0;
	if (l<=segL && segR<=r) return tree[node];
	pushDown(node);
	int mid=segL+segR>>1;
	return merge(query(node*2, segL, mid, l, r), query(node*2+1, mid, segR, l, r));
}

ll rebuild(int node, int segL, int segR) {
	if (segL==segR-1) return tree[node];
	pushDown(node);
	int mid=segL+segR>>1;
	return tree[node]=merge(rebuild(node*2, segL, mid), rebuild(node*2+1, mid, segR));
}

void printTree() {
	for (int i=0; i<TSZ*2; i++) cout << tree[i] << ' '; cout << endl;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	fill(lazy, lazy+TSZ*2, 1LL);
	fill(tree, tree+TSZ*2, 1LL);

	int N,M; cin>>N>>M;
	for (int i=0; i<M; i++) cin>>qs[i][0]>>qs[i][1]>>qs[i][2], qs[i][0]--;

	ll cur;
	for (int i=0; i<M; i++) {
		upt(1, 0, TSZ, qs[i][0], qs[i][1], qs[i][2]);
	}

	

	bool gd=1;
	for (int i=0; i<M; i++) {
		if (query(1, 0, TSZ, qs[i][0], qs[i][1])!=qs[i][2]) gd=0;
	}

	rebuild(1, 0, TSZ);
	if (*max_element(tree+TSZ, tree+TSZ+N)>1e9) gd=0;

	if (gd) {
		for (int i=0; i<N; i++) cout << tree[i+TSZ] << ' '; cout << endl;
	}
	else cout << "Impossible\n";
}
