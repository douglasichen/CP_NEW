# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int t, n, l[N], r[N], ans=0;
vector <int> adj[N];

ll DFS(int v){
	ll sum=0;
	for (int u : adj[v]) sum += DFS(u)
	if (sum < ll(l[v])) {
		++ans;
		return r[v];
	}
	return min(ll(r[v]), sum);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>t;
	while (t--) {
		cin >> n;
		for (int i=2,p; i <= n; ++ i) cin>>p, adj[p].push_back(i);
		for (int i = 1; i <= n; ++ i) cin>>l[i]>>r[i];
		DFS(1);
		cout << ans << "\n";
	}
}