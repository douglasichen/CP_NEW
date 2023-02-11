#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int TSZ=1<<17, INF=1e9+1e5+1;
int tree[TSZ*2], lazy[TSZ*2];

int merge(int a, int b) {
	return max(a,b);
}

void down(int node) {
	int left=node*2, right=node*2+1;
	if (lazy[node]) {
		lazy[left]+=lazy[node];
		lazy[right]+=lazy[node];
		tree[left]+=lazy[node];
		tree[right]+=lazy[node];
	}
	lazy[node]=0;
}

int lb(int node, int segL, int segR, int val) {
	if (segR-segL==1) return segL;
	
	down(node);
	int left=node*2, right=node*2+1, mid=segL+segR>>1;
	if (tree[left]>=val) {
		return lb(left, segL, mid, val);
	}
	return lb(right, mid, segR, val);
}

int getVal(int node, int segL, int segR, int pos) {
	if (pos<segL || pos>=segR) return 0;
	if (pos==segL && pos==segR-1) return tree[node];

	down(node);
	int mid=segL+segR>>1;
	return merge(getVal(node*2, segL, mid, pos), getVal(node*2+1, mid, segR, pos));
}

int incr(int node, int segL, int segR, int l, int r) {
	if (r<=segL || l>=segR) return tree[node];
	if (l<=segL && segR<=r) {
		lazy[node]++;
		tree[node]++;
		return tree[node];
	}
	down(node);
	int mid=segL+segR>>1;
	return tree[node]=merge(incr(node*2, segL, mid, l, r), incr(node*2+1, mid, segR, l, r));
}


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	fill(tree,tree+TSZ*2, INF);
	ms(lazy,0);

	int N,M; cin>>N>>M;
	for (int i=0; i<N; i++) cin>>tree[i+TSZ];
	sort(tree+TSZ, tree+TSZ+N);
	for (int i=TSZ-1; i; i--) tree[i]=merge(tree[i<<1], tree[i<<1|1]);

	for (int m=0; m<M; m++) {
		char c; int a,b; cin>>c>>a>>b;
		if (c=='F') {
			int p1=lb(1,0,TSZ,b);
			int L=p1, R=min(p1+a,N);

			int x=getVal(1,0,TSZ,R-1), y=getVal(1,0,TSZ,R);
			if (x==y) {
				int p2=lb(1,0,TSZ,x), len=R-p2;
				int p3=lb(1,0,TSZ,x+1);
				incr(1,0,TSZ,p3-len,p3);
				R=p2;
			}
			incr(1,0,TSZ,L,R);
		}
		else {
			int L=lb(1,0,TSZ,a), R=lb(1,0,TSZ,b+1);
			cout << R-L << endl;
		}
	}
}