#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

#define ll long long
void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,P; cin>>N>>P;
	vector<ll> C(N), U(N);
	for (int i=0; i<N; i++) cin>>C[i]>>U[i];

	vector<vector<vector<int>>> G(N);
	vector<int> deg(N);
	for (int i=0,a,b,w; i<P; i++) {
		cin>>a>>b>>w; a--, b--;
		G[a].push_back({b,w});
		deg[b]++;
	}

	stack<int> S;
	for (int i=0; i<N; i++)
		if (deg[i]==0)
			S.push(i);
	
	vector<int> ans;
	while (!S.empty()) {
		int node=S.top(); S.pop();
		if (G[node].size()==0 && C[node])
			ans.push_back(node);
		
		for (vector<int> child : G[node]) {
			deg[child[0]]--;
			C[child[0]]+=child[1]*C[node];
			if (deg[child[0]]==0)
				C[child[0]]=max(0LL, C[child[0]]-U[child[0]]),
				S.push(child[0]);
		}
	}

	sort(ans.begin(), ans.end());
	if (ans.size()) {	
		for (int i : ans) {
			cout << i+1 << " " << C[i] << endl;
		}
	}
	else cout << "NULL" << endl;
}