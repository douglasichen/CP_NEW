#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int L; cin>>L;
	while (L--) {
		int N; cin>>N;
		map<string, vector<string>> G;
		vector<string> V(N);
		for (int i=0; i<N; i++) cin>>V[i];
		for (int i=0; i<N; i++) {
			G[V[i]].push_back(V[(i+1)%N]);
			G[V[(i+1)%N]].push_back(V[i]);
		}
		
		string root=V.back();
		sort(V.begin(), V.end());
		V.resize(unique(V.begin(), V.end()) - V.begin());

		stack<pair<string,int>> st; st.push({root,0});
		map<string,bool> vis; vis[root]=1;
		int ans=0;
		while (st.size()) {
			pair<string,int> node=st.top(); st.pop();
			ans=max(ans, node.second);
			for (string child : G[node.first]) {
				if (!vis[child]) {
					vis[child]=1;
					st.push({child, node.second+1});
				}
			}
		}
		cout << N*10-ans*2*10 << endl;
	}	
}