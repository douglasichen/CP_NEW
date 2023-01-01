#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<string> words;
	for (int i=0; i<N; i++) {
		string s; cin>>s;
		words.push_back(s);
		words.push_back(s);
	}
	char sC; cin>>sC;

	// create graph
	vector<vector<vector<int>>> G(N<<1); // cost, id
	for (int a=0; a<N*2; a++) {
		for (int b=0; b<N*2; b++) {
			if (a!=b) {
				for (int sz=1; sz<min(words[a].size(), words[b].size()); sz++) {
					if (words[a].substr(words[a].size()-sz, sz)==words[b].substr(0,sz)) {
						G[a].push_back({words[b].size()-sz,b});
						break;
					}
				}
			}
		}
	}
	int ans=0;
	priority_queue<vector<int>, vector<vector<int>>> pq;
	for (int start=0; start<N*2; start++) {
		if (words[start][0]==sC) {
			vector<int> vis(N*2);
			pq.push({words[start].size(), start});
			while (!pq.empty()) {
				vector<int> top=pq.top(); pq.pop();
				vis[top[1]]=1;
				ans=max(ans,top[0]);
				for (vector<int> child : G[top[1]]) {
					if (!vis[child[1]]) {
						pq.push({top[0]+child[0], child[1]});
					}
				}
			}
		}
	}
	cout << ans << endl;

