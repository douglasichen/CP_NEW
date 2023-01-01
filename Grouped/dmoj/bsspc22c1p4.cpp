#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,T; cin>>N>>T;
	vector<int> V(N+1);
	for (int i=0; i<N; i++) cin>>V[i];

	int mx=0, ans=0,sm=0;
	for (int i=0; i<N; i++) {
		mx=max(V[i],mx);
		sm+=V[i];
		if (sm-mx<=T) ans=i;
	}
	cout << ans << endl;
}