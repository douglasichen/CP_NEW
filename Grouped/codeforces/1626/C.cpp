#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		vector<int> K(N), H(N);
		map<int,int> M, start;
		for (int i=0; i<N; i++) cin>>K[i];
		for (int i=0; i<N; i++) cin>>H[i];
		for (int i=0; i<N; i++) {
			int k=K[i], h=H[i], a=k-h+1, b=k;
			M[a]++, M[b+1]--;
			start[a]++;
		}
		for (auto i1=M.begin(), i2=M.begin(); i2!=M.end(); i1++, i2++) {
			if (i2==i1) i2++;
			i2->second+=i1->second;
		}
		ll ans=0, from=0;
		for (auto i : M) {
			int pos=i.first, val=i.second;
			if (val==start[pos]) {
				// add behind
				if (from) {
					ll L=pos-from;
					ans+=L*(L+1)/2;
				}
				
				// set new from
				if (val) from=pos;
				else from=0;
			}
		}
		cout << ans << endl;
	}	
}