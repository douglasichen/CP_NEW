#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int TSZ=1<<20;
int INF=2e9;
ll pre[TSZ*2], suf[TSZ*2], ar[TSZ];

ll merge(ll a, ll b) {
	return min(a,b);
}

ll uptPre(int node, int segL, int segR, int p, int v) {
	if (p<segL || p>=segR) return pre[node];
	if (p==segL && p==segR-1) return pre[node]+=v;

	int mid=segL+segR>>1;
	return pre[node]=merge(uptPre(node*2, segL, mid, p, v), uptPre(node*2+1, mid, segR, p, v));
}

ll uptSuf(int node, int segL, int segR, int p, int v) {
	if (p<segL || p>=segR) return suf[node];
	if (p==segL && p==segR-1) return suf[node]+=v;

	int mid=segL+segR>>1;
	return suf[node]=merge(uptSuf(node*2, segL, mid, p, v), uptSuf(node*2+1, mid, segR, p, v));
}

ll queryPre(int node, int segL, int segR, int l, int r) {
	if (r<=segL || l>=segR) return INF;
	if (l<=segL && segR<=r) return pre[node];
	
	int mid=segL+segR>>1;
	return merge(queryPre(node*2, segL, mid, l, r), queryPre(node*2+1, mid, segR, l, r));
}

ll querySuf(int node, int segL, int segR, int l, int r) {
	if (r<=segL || l>=segR) return INF;
	if (l<=segL && segR<=r) return suf[node];
	
	int mid=segL+segR>>1;
	return merge(querySuf(node*2, segL, mid, l, r), querySuf(node*2+1, mid, segR, l, r));
}


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	memset(pre, 0x7f7f7f7f, sizeof(pre));
	memset(suf, 0x7f7f7f7f, sizeof(suf));

	int N,Q; cin>>N>>Q;
	for (int i=0; i<N; i++) cin>>ar[i], pre[TSZ+i]=ar[i]+i, suf[TSZ+i]=ar[i]+(N-i-1);
	for (int i=TSZ-1; i; i--) pre[i]=merge(pre[i<<1], pre[i<<1|1]), suf[i]=merge(suf[i<<1], suf[i<<1|1]);

	while (Q--) {
		int m, k; cin>>m>>k; k--;
		if (m==1) {
			int x; cin>>x;
			uptPre(1, 0, TSZ, k, x-ar[k]);
			uptSuf(1, 0, TSZ, k, x-ar[k]);
			ar[k]=x;
		}
		else {
			cout << min(querySuf(1, 0, TSZ, 0, k+1)-(N-k-1), 
						queryPre(1, 0, TSZ, k, N)-k) << endl;
		}
	}
}