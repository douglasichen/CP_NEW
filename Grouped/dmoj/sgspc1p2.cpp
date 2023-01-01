#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,K=0; cin>>N;
	while ((1<<K+1)<N) K++;
	
	vector<int> ans(K+1);
	for (int e=0; e<=K; e++) {
		int val=1<<e;
		cout << "$ " << N;
		for (int i=0; i<N; i++) cout << ' ' << i;
		cout << ' ' << val << endl << flush;
		int Y; cin>>Y;
		ans[e]=Y;
	}

	cout << "! " << K;
	for (int i : ans) cout << ' ' << i;
	cout << endl << flush;
}