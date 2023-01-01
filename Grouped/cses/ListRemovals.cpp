#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int SZ=1<<20;
int tree[SZ*2], arr[SZ], ans[SZ];

int merge(int a, int b) {
	return a+b;
}

int modify(int node, int segL, int segR, int pos, int val) {
	if (segL==pos && segR-1==pos) return tree[node]=val;
	if (pos<segL || pos>=segR) return tree[node];
	int mid=segL+segR>>1;
	return tree[node]=merge(modify(node*2, segL, mid, pos, val), modify(node*2+1, mid, segR, pos, val));
}

int query(int node, int segL, int segR, int val, int sm) {
	if (segR-segL==1) return segL;
	int left=node*2, right=node*2+1, mid=segL+segR>>1, lSm=sm-tree[right], rSm=sm;
	if (lSm>=val) return query(left, segL, mid, val, lSm);
	return query(right, mid, segR, val, rSm);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	memset(tree, 0, sizeof(tree));

	int N; cin>>N;
	for (int i=0; i<N; i++) cin>>arr[i], tree[i+SZ]=1;
	for (int i=SZ-1; i; i--) tree[i]=merge(tree[i<<1], tree[i<<1|1]);

	for (int i=0, p; i<N; i++) {
		cin>>p;
		p=query(1, 0, SZ, p, N-i);
		ans[i]=arr[p];
		modify(1, 0, SZ, p, 0);
	}
	for (int i=0; i<N; i++)
		cout << ans[i] << ' ';
	cout << endl;
}