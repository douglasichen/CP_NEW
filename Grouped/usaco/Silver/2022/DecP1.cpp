#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int MAXN=2e5;
int ar[MAXN];
vector<int> G[MAXN];
bool vis[MAXN];

ll dp[MAXN];
vector<vector<ll>> ans;

void solve(int node, int beh) {
	for (int child : G[node]) {
		if (child!=beh) {
			if (dp[child]==0) {
				solve(child,node);
			}
		}
	}
	for (int child : G[node]) {
		if (child!=beh) {
			if (dp[child]<0) {
				solve(child, node);
				ans.push_back({child,node,-dp[child]});
			}
		}
	}
	for (int child : G[node]) {
		if (child!=beh) {
			if (dp[child]>0) {
				ans.push_back({node,child,dp[child]});
				solve(child, node);
			}
		}
	}
}

ll sm(int node, int beh) {
	dp[node]=ar[node];
	for (int child : G[node]) 
		if (child!=beh)
			dp[node]+=sm(child, node);
	return dp[node];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	memset(vis, 0, sizeof(vis));
	memset(dp, 0, sizeof(dp));

	ll need=0;
	int N; cin>>N;
	for (int i=0; i<N; i++) cin>>ar[i], need+=ar[i];
	for (int i=0; i<N-1; i++) {
		int a,b; cin>>a>>b; a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	// does it matter where you use root, no, i dont think so
	need/=N;
	for (int i=0; i<N; i++) ar[i]=need-ar[i];

	sm(0,0);
	// for (int i=0; i<N; i++) cout << dp[i] << ' '; cout << endl;
	solve(0,0);

	cout << ans.size() << endl;
	for (vector<ll> a : ans) {
		cout << a[0]+1 << ' ' << a[1]+1 << ' ' << a[2] << endl;
	}
}