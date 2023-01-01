#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M,N; cin>>M>>N;
	vector<vector<vector<int>>> G(1e6+1);
	for (int y=1; y<=M; y++) {
		for (int x=1, val; x<=N; x++) {
			cin>>val;
			G[val].push_back({y,x});
		}
	}	
	vector<bool> used(1e6+1);
	vector<vector<bool>> vis(M+1, vector<bool>(N+1));
	vis[M][N]=1;
	stack<vector<int>> S; S.push({M,N});
	bool ans=0;
	while (!S.empty()) {
		vector<int> node=S.top(); S.pop();
		int val=node[0]*node[1];
		if (used[val]) continue;
		used[val]=1;
		if (node[0]==1 && node[1]==1) {
			ans=1;
			break;
		}
		for (vector<int> child : G[val]) {
			if (!vis[child[0]][child[1]] && !used[child[0]*child[1]]) {
				vis[child[0]][child[1]]=1;
				S.push(child);
			}
		}
	}
	cout << (ans ? "yes" : "no") << endl;
}