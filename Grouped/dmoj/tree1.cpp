#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


vector<vector<int>> G(4, vector<int>(4));
vector<bool> vis(4);
bool ans=1;

void dfs(int node, int beh) {
	vis[node]=1;
	for (int child=0; child<4; child++) {
		if (child!=beh && G[node][child]) {
			if (vis[child]) {
				ans=0;
				return;
			}
			dfs(child,node);
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (auto &v : G) for (auto &i : v) cin>>i;
	dfs(0,0);
	for (int i=1; i<4; i++) if (!vis[i]) ans=0;
	cout << (ans ? "Yes" : "No") << endl;
}