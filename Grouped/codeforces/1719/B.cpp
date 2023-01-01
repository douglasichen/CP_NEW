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
		int N,K; cin>>N>>K;
		int md=K%4;
		vector<vector<int>> V;
		if (md) {
			if (md==2) {
				for (int i=1; i<=N; i+=2) {
					if ((i+1)%4==0) V.push_back({i,i+1});
					else V.push_back({i+1,i});
				}
			}
			else {
				for (int i=1; i<=N; i+=2) V.push_back({i,i+1});
			}
		}
		cout << (V.size() ? "YES" : "NO") << endl;
		for (vector<int> &v : V) cout << v[0] << ' ' << v[1] << endl;
	}	
}