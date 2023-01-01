#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int Q; cin>>Q;
	while (Q--) {
		string T; cin>>T;
		int N; cin>>N;
		vector<string> V(N);
		for (int i=0; i<N; i++) cin>>V[i];
		auto srt=[&](string &a, string &b) {return a.size()>b.size();};
		auto srt2=[&](int &a, int &b) {return V[a].size()>V[b].size();};
		vector<int> order;
		for (int i=0; i<N; i++) order.push_back(i);
		sort(order.begin(), order.end(), srt2);
		sort(V.begin(), V.end(), srt);
		
		vector<vector<int>> ans;
		int mx=0;
		while (mx<T.size()) {
			vector<int> reach={-1,0}; // index, bnd
			for (int i=0; i<=mx; i++) {
				for (int o=0; o<N; o++) {
					string s=V[o];
					int bnd=i+s.size();
					if (bnd<=mx) break;
					if (T.substr(i,s.size())==s && bnd>reach[1]) reach={o, bnd};
				}
			}
			if (reach[1]>mx) {
				ans.push_back({order[reach[0]]+1, reach[1]-V[reach[0]].size()+1});
				mx=reach[1];
			}
			else {
				ans.clear();
				break;
			}
		}
		if (ans.size()==0) cout << -1 << endl;
		else {
			cout << ans.size() << endl;
			for (vector<int> v : ans) cout << v[0] << ' ' << v[1] << endl;
		}
	}
}