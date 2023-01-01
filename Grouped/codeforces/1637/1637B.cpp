#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		ll N, ans=0; cin>>N;
		vector<int> V(N);
		for (int i=0; i<N; i++) cin>>V[i];
		for (int l=0; l<N; l++) {
			for (int r=l, o=0; r<N; r++) {
				o+=V[r]==0;
				ans+=o+r-l+1;
			}
		}
		cout << ans << endl;
	}
}