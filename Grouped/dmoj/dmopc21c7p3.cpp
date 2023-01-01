#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	vector<int> B(N+1), hit(N+1);
	for (int i=1; i<=N; i++) cin>>B[i];
	
	vector<vector<int>> G(N+1);
	for (int i=0,a,b; i<M; i++) cin>>a>>b, G[a].push_back(b);

	int ans=0;
	for (int i=1; i<=N; i++) {
		int b=B[i];
		if (hit[i]%2) b=!b;
		ans+=b;
		if (hit[i]%2 || B[i]) for (int child : G[i]) hit[child]++;
	}
	// cout << endl;
	cout << ans << endl;
}