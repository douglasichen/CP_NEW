#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int N,K,ans=0, e=0;
void solve(short sz, short sm, short prev) {
	if (sz==K) ans++;
	else {
		short lef=N-sm;
		if (sz==K-1) prev=max(prev, lef);
		for (; prev<=lef; prev++)
			solve(sz+1, sm+prev, prev);
	}
	// e++;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>K;
	solve(0,0,1);
	cout << ans << endl;
	// cout << e << endl;
}