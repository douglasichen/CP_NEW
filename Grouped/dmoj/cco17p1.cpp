#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int K, N=0, M=0, node=1, past=0; cin>>K;
	vector<vector<int>> E;

	if (K==0) {
		N=2, M=1;
		E.push_back({1,2});
	}
	while (K) {
		int n=sqrt(K<<1)+2;
		while (n*(n-1)/2>K) n--;
		for (int i=node; i<node+n; i++) E.push_back({i, i<node+n-1 ? i+1 : node});
		if (past) E.push_back({past,node}), M++;
		N+=n;
		M+=n;
		node+=n;
		K-=n*(n-1)/2;

		past=node-1;
	}
	cout << N << ' ' << M << endl;
	for (vector<int> &e : E) cout << e[0] << " " << e[1] << endl;

}