#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define SZ(a) int(a.size())
#define endl '\n'
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=1e5+1, MAXM=2e5+1;
int on[MAXM], ord[MAXM], mstUse[MAXM], dsu[MAXN];
vector<int> edges[MAXM];
vector<vector<ll>> reses;

int root(int a) {
	return dsu[a]<0 ? a : dsu[a]=root(dsu[a]);
}

bool unite(int a, int b) {
	a=root(a), b=root(b);
	if (a==b) return 0;
	if (dsu[a]>dsu[b]) swap(a,b);
	dsu[a]+=dsu[b];
	dsu[b]=a;
	return 1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(on,0);
	ms(mstUse,0);

	iota(ord,ord+MAXM,0);

	int N,M,D; cin>>N>>M>>D;
	for (int i=0; i<M; i++) {
		if (i<N-1) on[i]=1;
		int a,b,c; cin>>a>>b>>c;
		edges[i]={c,a,b};
	}

	ll ans=INT_MAX;
	ll mnCost=LLONG_MAX;
	for (int i=0; i<M; i++) {
		int prev=edges[i][0];
		edges[i][0]=max(0,edges[i][0]-D);
		sort(ord, ord+M, [&](int a, int b) {
			if (edges[a][0]==edges[b][0]) return on[a]>on[b];
			return edges[a][0]<edges[b][0];
		});

		fill(dsu,dsu+MAXN,-1);
		ms(mstUse,0);
		ll mstCost=0;
		for (int o=0; o<M; o++) {
			int a=ord[o];
			if (unite(edges[a][1], edges[a][2])) mstUse[a]=1, mstCost+=edges[a][0];
		}
		int res=0;
		for (int a=0; a<M; a++) res+=(on[a]^mstUse[a]);
		reses.push_back({mstCost, ll((res+1)/2)});
		edges[i][0]=prev;
	}
	
	for (vector<ll> p : reses) mnCost=min(mnCost,p[0]);
	for (vector<ll> p : reses) if (p[0]==mnCost) ans=min(ans,p[1]);
	cout << ans << endl;
}