#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	for (int t=0; t<T; t++) {
		int N; cin>>N;
		double mn=1e9,mx=0;
		vector<double> X(N);
		for (double &e : X) cin>>e;
		for (int i=0,e; i<N; i++)
			cin>>e,
			mn=min(mn, X[i]-e),
			mx=max(mx, X[i]+e);
		double ans=(mn+mx)/2.0;
		cout << setprecision(20) << ans << endl;
	}	
}