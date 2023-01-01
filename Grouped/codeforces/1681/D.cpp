#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll unsigned long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	ll N,X; cin>>N>>X;
	map<ll,bool> vis;
	queue<vector<ll>> Q; Q.push({X,0}); // val, dis
	while (!Q.empty()) {
		vector<ll> node=Q.front(); Q.pop();
		string s=to_string(node[0]);
		if (s.size()==N) {
			cout << node[1] << endl;
			return 0;
		}
		for (char c : s) {
			ll res=node[0]*(c-'0');
			if (!vis[res]) {
				vis[res]=1;
				Q.push({res,node[1]+1});
			}
		}
	}
	cout << -1 << endl;
}