#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int TSZ=1<<20, UNIT=0;
int tree[TSZ*2], nxt[TSZ], order[TSZ], qs[TSZ][2], ans[TSZ];

int merge(int a, int b) {
	return a+b;
}

int upt(int node, int segL, int segR, int pos, int val) {
	if (pos<segL || pos>=segR) return tree[node];
	if (pos==segL && pos==segR-1) return tree[node]=val;
	int mid=segL+segR>>1;
	return tree[node]=merge(upt(node*2, segL, mid, pos, val), upt(node*2+1, mid, segR, pos, val));
}

int query(int node, int segL, int segR, int L, int R) {
	if (R<=segL || L>=segR) return UNIT;
	if (L<=segL && segR<=R) return tree[node];
	int mid=segL+segR>>1;
	return merge(query(node*2, segL, mid, L, R), query(node*2+1, mid, segR, L, R));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	memset(tree, 0, sizeof(tree));
	memset(nxt, 0, sizeof(nxt));
	
	// connect same values to the next same value
	int N, Q; cin>>N>>Q;
	map<int, int> at;
	for (int i=1, val; i<=N; i++) {
		cin>>val;
		if (at[val]) nxt[at[val]]=i;
		else tree[i+TSZ]=1;
		at[val]=i;
	}
	for (int i=TSZ-1; i; i--) tree[i]=merge(tree[i<<1], tree[i<<1|1]);

	for (int q=0; q<Q; q++) cin>>qs[q][0]>>qs[q][1];
	iota(order, order+Q, 0);

	auto srt=[&](int a, int b){return qs[a][0]<qs[b][0];};
	sort(order, order+Q, srt);
	

	int k=1;
	for (int i=0; i<Q; i++) {
		int q=order[i], a=qs[q][0], b=qs[q][1];

		for (; k<a; k++) {
			upt(1, 0, TSZ, k, 0);
			upt(1, 0, TSZ, nxt[k], 1);
		}
		ans[q]=query(1, 0, TSZ, a, b+1);
	}
	for (int i=0; i<Q; i++) cout << ans[i] << endl;
}