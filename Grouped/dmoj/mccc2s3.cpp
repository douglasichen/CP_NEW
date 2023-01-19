#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()
#pragma GCC optimize ("Ofast")

const int MAXM=1e5;
vector<int> edges[MAXM], qs[MAXM];
int ans[MAXM], dsu[MAXM];

int root(int a) {
	return dsu[a]<0 ? a : dsu[a]=root(dsu[a]);
}

void unify(int a, int b) {
	a=root(a), b=root(b);
	if (a==b) return;
	if (dsu[a]>dsu[b]) swap(a,b);
	dsu[a]+=dsu[b];
	dsu[b]=a;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	fill(ans, ans+MAXM, 128);

	int N,M,Q; cin>>N>>M>>Q;
	for (int i=0,a,b,c; i<M; i++) {
		cin>>a>>b>>c; a--, b--;
		edges[i]={a,b,c};
	}
	for (int i=0,a,b; i<Q; i++) {
		cin>>a>>b; a--, b--;
		qs[i]={a,b};
	}

	for (int val=0; val<128; val++) {
		fill(dsu, dsu+N, -1);
		for (int i=0; i<M; i++) {
			if ((edges[i][2]|val)==val) unify(edges[i][0], edges[i][1]);
		}
		for (int i=0; i<Q; i++) {
			if (root(qs[i][0])==root(qs[i][1])) ans[i]=min(ans[i], val);
		}
	}
	for (int i=0; i<Q; i++)
		cout << ans[i] << endl;
	// cout << endl;
}