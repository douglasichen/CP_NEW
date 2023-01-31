#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define SZ(a) int(a.size())
#define endl '\n'
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=1e5+1, TSZ=1<<20;
ll psa[MAXN*2], tree[TSZ*2], INF=1e15;

ll merge(ll a, ll b) {
	return max(a,b);
}

ll query(int node, int segL, int segR, int l, int r) {
	if (r<=segL || l>=segR) return -INF;
	if (l<=segL && segR<=r) return tree[node];
	int mid=segL+segR>>1;
	return merge(query(node*2, segL, mid, l, r), query(node*2+1, mid, segR, l, r)); 
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,K; cin>>N>>K;
	for (int i=1; i<=N; i++) cin>>psa[i], psa[i+N]=psa[i];
	for (int i=1; i<=N*2; i++) psa[i]+=psa[i-1];

	for (int i=1; i<=N*2; i++) tree[i+TSZ]=psa[i];
	for (int i=TSZ-1; i; i--) tree[i]=merge(tree[i<<1], tree[i<<1|1]);

	ll ans=-INF;
	for (int i=1; i<=N*2; i++) {
		int R=min(N*2+1,i+K);
		ans=max(ans, query(1,0,TSZ,i,R) - psa[i-1]);
	}

	cout << ans << endl;
	
}