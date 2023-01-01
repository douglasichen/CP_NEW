#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
 
bool solve(int N, vector<vector<int>> &V) {
	vector<vector<int>> G(N), W(N+1);
	for (int i=0; i<N; i++) {
		int a=V[i][0], b=V[i][1];
		if (a==b) return 0;
		W[a].push_back(i), W[b].push_back(i);
	}
	
	for (int i=1; i<=N; i++) {
		vector<int> v=W[i];
		if (v.size()!=2) return 0;
		G[v[0]].push_back(v[1]);
		G[v[1]].push_back(v[0]);
	}

	stack<int> S;
	vector<bool> vis(N+1), C(N+1);
	for (int i=0; i<N; i++) {
		if (vis[i]) continue;
		S.push(i); vis[i]=1;
		while (!S.empty()) {
			int top=S.top(); S.pop();
			for (int child : G[top]) {
				if (!vis[child]) {
					vis[child]=1;
					S.push(child);
					C[child]=!C[top];
				}
			}
		}
	}
	for (int i=0; i<N; i++) {
		for (int child : G[i]) {
			if (C[i]==C[child]) return 0;
		}
	}
	return 1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
 
	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		vector<vector<int>> V(N, vector<int>(2));
		for (int i=0; i<N; i++) cin>>V[i][0]>>V[i][1];
		bool ans=solve(N,V);
		cout << (ans ? "YES" : "NO") << endl;
	}
}