#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		long long N,Z; cin>>N>>Z;
		long long ans=0;
		for (int i=0,e; i<N; i++) cin>>e, ans=max(ans,e|Z);
		cout << ans << endl;
		
	}
}