#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=100001;
vector<int> edges[MAXN];
int dest[MAXN], dsu[MAXN];

int root(int a) {
	return dsu[a]<0 ? a : dsu[a]=root(dsu[a]);
}

void unite(int a, int b) {
	a=root(a), b=root(b);
	if (a==b) return;
	if (dsu[a]>dsu[b]) swap(a,b);
	dsu[a]+=dsu[b];
	dsu[b]=a;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int C,E,D; cin>>C>>E>>D;
	for (int i=0; i<E; i++) {
		int a,b,c; cin>>a>>b>>c;
		edges[i]={a,b,c};
	}
	for (int i=0; i<D; i++) cin>>dest[i];
	int L=0, R=MAXN;
	while (L<R) {
		int W=L+R+1>>1;
		// check if W is good -> can add all edges >=W weight
		fill(dsu,dsu+C+1,-1);
		for (int i=0; i<E; i++) {
			int a=edges[i][0], b=edges[i][1], c=edges[i][2];
			if (c>=W) unite(a,b);
		}
		bool gd=1;
		for (int i=0; i<D; i++) if (root(1)!=root(dest[i])) gd=0;
		if (gd) L=W;
		else R=W-1;
	}
	cout << L << endl;
}