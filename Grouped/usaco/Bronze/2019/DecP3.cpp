#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	// freopen("lineup.in", "r", stdin);
	// freopen("lineup.out", "w", stdout);

	int N; cin>>N;
	string s;
	map<string, vector<string>> G;
	vector<string> cows={"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
	for (string c : cows) G[c]={};

	for (int i=0; i<N; i++) {
		string a,b; cin>>a;
		cin>>s>>s>>s>>s;
		cin>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	stack<string> Q;
	map<string,bool> vis;
	
	for (pair<string, vector<string>> p : G) {
		if (vis[p.first] || p.second.size()>1) continue;
		
		Q.push(p.first);
		vis[p.first]=1;
		while (!Q.empty()) {
			string node=Q.top(); Q.pop();
			cout << node << endl;
			for (string child : G[node])
				if (!vis[child])
					Q.push(child),
					vis[child]=1;
		}
	}
}