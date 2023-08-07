#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAX_K=201, MAX_N=2001, INF=INT_MAX;

vector<vector<int>> gr[MAX_N];
int dp[MAX_K][MAX_N];
bitset<MAX_N> vis;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int k=0; k<MAX_K; k++)
		for (int i=0; i<MAX_N; i++)
			dp[k][i]=INF;

	int K,N,M; cin>>K>>N>>M;
	for (int i=0; i<M; i++) {
		int a,b,t,h; cin>>a>>b>>t>>h;
		gr[a].push_back({t,h,b});
		gr[b].push_back({t,h,a});
	}
	int A,B; cin>>A>>B;

	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	pq.push({0,0,A}); // time, hull, node
	dp[0][A]=0;
	while (SZ(pq)) {
		vector<int> node=pq.top(); pq.pop();
		if (vis[node[2]]) continue;
		vis[node[2]]=1;
		for (vector<int> child : gr[node[2]]) {
			if (!vis[child[2]]) {
				child[0]+=node[0];
				child[1]+=node[1];
				if (child[1]<K && child[0]<dp[child[1]][child[2]]) {
					dp[child[1]][child[2]]=child[0];
					pq.push(child);
				}
			}
		}
	}
	int ans=INF;
	for (int k=0; k<K; k++) ans=min(ans, dp[k][B]);
	cout << (ans==INF ? -1 : ans) << endl;
}