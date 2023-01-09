#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int TSZ=1<<20;
int tree[TSZ*2];

int merge(int a,int b) {
	return max(a,b);
}

int upt(int node, int segL, int segR, int pos, int val) {
	if (pos<segL || pos>=segR) return tree[node];
	if (pos==segL && pos==segR-1) return tree[node]=val;
	int mid=segL+segR>>1;
	return tree[node]=merge(upt(node*2, segL, mid, pos, val), upt(node*2+1, mid, segR, pos, val));
}

int query(int node, int segL, int segR, int val) {
	if (segR-segL==1) return segL;
	int left=node*2, right=node*2+1, mid=segL+segR>>1;
	if (tree[left]>=val) return query(left, segL, mid, val);
	return query(right, mid, segR, val);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	ms(tree,0);

	int N,Q; cin>>N>>Q;

	for (int i=0; i<N; i++) {
		cin>>tree[i+TSZ];
	}
	tree[N+TSZ]=INT_MAX;
	for (int i=TSZ-1; i; i--) tree[i]=merge(tree[i<<1], tree[i<<1|1]);
	for (int i=0; i<Q; i++) {
		int x; cin>>x;
		int pos=query(1,0,TSZ,x);
		if (pos==N) pos=-1;
		else upt(1,0,TSZ,pos,tree[TSZ+pos]-x);
		cout << pos+1 << ' ';
	}
	cout << endl;
}