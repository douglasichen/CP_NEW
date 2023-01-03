#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int UNIT = 0;
const int TSZ = 1 << 20;
ll tree[TSZ*2], lazy[TSZ*2];

int merge(int a, int b){
    return max(a, b);
}

void pushDown(int i){
    tree[i*2] += lazy[i];
    tree[i*2+1] += lazy[i];
    lazy[i*2] += lazy[i];
    lazy[i*2+1] += lazy[i];
    lazy[i] = 0;
}

int query(int i, int segL, int segR, int l, int r){
    if(r <= segL || l >= segR) return UNIT;
    if(l <= segL && segR <= r) return tree[i];
    pushDown(i);
    int mid = (segL+segR)/2;
    return merge(query(i*2, segL, mid, l, r), query(i*2+1, mid, segR, l, r));
}

int upd(int i, int segL, int segR, int l, int r, int v){
    if(r <= segL || l >= segR) return tree[i];
    if(l <= segL && segR <= r){
        lazy[i] += v;
        return tree[i] += v;
    }
    pushDown(i);
    int mid = (segL+segR)/2;
    return tree[i] = merge(upd(i*2, segL, mid, l, r, v), upd(i*2+1, mid, segR, l, r, v));
}

// int upd(int i, int segL, int segR, int L, int R, int val) {
// 	if (L>=segR || R<=segL) return tree[i];
// 	if (L<=segL && segR<=R) {
// 		lazy[i]+=val;
// 		return tree[i]+=val;
// 	}
// 	pushDown(i);
// 	int mid=segL+segR>>1;
// 	return tree[i]=max(upd(i*2, segL, mid, L, R, val), upd(i*2+1, mid, segR, L, R, val));
// }





// int upd(int i, int segL, int segR, int pos, int val) {
// 	if (pos<=segL || segR<=pos) return tree[i];
// 	// pushDown(i);
// 	int mid=segL+segR>>1;
// 	return tree[i]=upd(i*2, segL, mid, pos, val) + upd(i*2+1, mid, segR, pos, val);
// }


ll query(int node, int segL, int segR, int L, int R) {
	if (R<=segL || segR<=L) return UNIT;
	if (L<=segL && segR<=R) return tree[node];
	int mid=segL+segR>>1;
	return query(node*2, segL, mid, L, R) + query(node*2+1, mid, segR, L, R);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	memset(tree, 0, sizeof(tree));
	
	int N,Q; cin>>N>>Q;
	for (int i=0; i<N; i++) cin>>tree[TSZ+i];
	for (int i=TSZ-1; i; i--) tree[i]=tree[i<<1]+tree[i<<1|1];

	while (Q--) {
		int L,R; cin>>L>>R;
		L--;
		cout << query(1, 0, TSZ, L, R) << endl;
	}
}