#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<int> dsu;

int root(int &a) {
	return dsu[a]<0 ? a : dsu[a]=root(dsu[a]);
}

bool unite(int &a, int &b) {
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

	int N,D; cin>>N>>D;
	dsu.assign(N+1,-1);
	for (int i=0,x,y,extra=0; i<D; i++) {
		cin>>x>>y;
		extra+=!unite(x,y);

		int ans=0;
		vector<int> sorted=dsu;
		sort(sorted.begin(), sorted.end());
		for (int o=0; o<=extra && sorted[o]<0; o++) ans+=-sorted[o];
		cout << ans-1 << endl;
	}
}