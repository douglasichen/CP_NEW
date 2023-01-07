#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a, x, sizeof(a))

const int TSZ=1<<20;
ll ar[TSZ], qs[TSZ][2], ord[TSZ], psa[TSZ], tree[TSZ*2], lazy[TSZ*2], ans[TSZ];

ll merge(ll a, ll b) {
	return a+b;
}

void pushDown(int node, int segL, int mid, int segR) {
	if (lazy[node]) {
		int left=node*2, right=node*2+1;
		lazy[left]=lazy[node];
		lazy[right]=lazy[node];
		
		tree[left]=lazy[node]*(mid-segL);
		tree[right]=lazy[node]*(segR-mid);
		
		lazy[node]=0;
	}
}

ll upt(int node, int segL, int segR, int l, int r, ll val) {
	if (r<=segL || l>=segR) return tree[node];
	if (l<=segL && segR<=r) {
		lazy[node]=val;
		return tree[node]=val*(segR-segL);
	}

	int mid=segL+segR>>1;
	pushDown(node, segL, mid, segR);
	return tree[node]=merge(upt(node*2, segL, mid, l, r, val), upt(node*2+1, mid, segR, l, r, val));
}

ll query(int node, int segL, int segR, int l, int r) {
	if (r<=segL || l>=segR) return 0;
	if (l<=segL && segR<=r) return tree[node];
	int mid=segL+segR>>1;
	pushDown(node, segL, mid, segR);
	return merge(query(node*2, segL, mid, l, r), query(node*2+1, mid, segR, l, r));
}

void printTree() {
	for (int i=0; i<TSZ*2; i++) cout << tree[i] << ' '; cout << endl;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(tree, 0);
	ms(lazy, 0);
	ms(psa, 0);

	int N,Q; cin>>N>>Q;
	for (int i=0; i<N; i++) cin>>ar[i], psa[i+1]=psa[i]+ar[i];
	for (int i=0; i<Q; i++) cin>>qs[i][0]>>qs[i][1], qs[i][0]--;
	iota(ord, ord+Q, 0);
	sort(ord, ord+Q, [](int a, int b) {
		return qs[a][0]>qs[b][0];
	});

	stack<int> st;
	int at=N-1;
	for (int o=0; o<Q; o++) {
		int i=ord[o], l=qs[i][0], r=qs[i][1];
		for (; at>=l; at--) {
			while (st.size() && ar[at]>=ar[st.top()]) st.pop();

			int bnd=(st.size() ? st.top() : N);
			st.push(at);
			upt(1, 0, TSZ, at, bnd, ar[at]);
		}
		// printTree();
		ans[i]=query(1, 0, TSZ, l, r)-(psa[r]-psa[l]);
	}
	for (int i=0; i<Q; i++) cout << ans[i] << endl;

}