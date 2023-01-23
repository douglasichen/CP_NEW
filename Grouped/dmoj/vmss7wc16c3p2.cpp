#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=2001;
int dsu[MAXN];

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

	int N,M,A,B; cin>>N>>M>>A>>B;
	fill(dsu,dsu+N+1,-1);
	for (int i=0; i<M; i++) {
		int x,y; cin>>x>>y;
		unify(x,y);
	}
	cout << (root(A)==root(B) ? "GO SHAHIR!" : "NO SHAHIR!") << endl;
}