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
		int N,sm=0; cin>>N;
		vector<int> A(N);
		for (int i=0; i<N; i++) cin>>A[i], sm+=A[i];
		if (sm<0) {
			sm*=-1;
			for (int &i : i) i*=-1;
		}
		vector<vector<int>> V;
		for (int r=1,l=0; r<N && sm; r+=2) {
			if (V[r]==1) sm--;
			else if (V[r]==-1) {
				V.push_back({l+1,r});
			}
			if (sm==0) V.push_back({l+1,r+1});
		}

		if (sm) cout << -1 << endl;
		else {
			cout << V.size() << endl;
			for (vector<int> &v : V) cout << v[0] << ' ' << v[1] << endl;
		}
	}	
}