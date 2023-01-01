#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int SZ=1<<20;
int INF=1e9;
int tree[SZ*2], ans[SZ], N, M;

int merge(int a, int b) {
	return max(a,b);
}

int modify(int node, int segL, int segR, int pos, int val) {
	if (pos<segL || pos>=segR) return tree[node];
	if (pos==segL && pos==segR-1) return tree[node]=val;
	
	int mid=segL+segR>>1;
	return tree[node]=merge(modify(node*2, segL, mid, pos, val), modify(node*2+1, mid, segR, pos, val));
}

int query(int node, int segL, int segR, int val) {
	if (segR-segL==1) return val<=tree[node] ? segL : N;
	// left: node*2, right: node*2+1;
	int left=node*2, right=node*2+1, mid=segL+segR>>1;
	if (val<=tree[left]) {
		// cout << segL << "," << segR << " to " << segL << " " << mid << endl;
		return query(left, segL, mid, val);
	}
	// cout << segL << "," << segR << " to " << mid << " " << segR << endl;
	return query(right, mid, segR, val);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	for (int i=0; i<N; i++) cin>>tree[i+SZ];
	for (int i=SZ-1; i; i--) tree[i]=merge(tree[i<<1], tree[i<<1|1]);

	for (int m=0; m<M; m++) {
		int X; cin>>X;
		// find a hotel that has value >=X.
		// if found: lower that hotel by X
		// otherwise: 0
		int pos=query(1, 0, SZ, X);
		if (pos<N) {
			modify(1, 0, SZ, pos, tree[SZ+pos]-X);
			ans[m]=pos+1;
		}
		else ans[m]=0;
		// for (int i=0; i<SZ*2; i++) cout << i << ' '; cout << endl;
		// for (int i=0; i<SZ*2; i++) cout << tree[i] << ' '; cout << endl;
	}
	for (int i=0; i<M; i++) cout << ans[i] << " "; cout << endl;
}