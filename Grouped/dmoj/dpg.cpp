#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=1e5+1;
int dp[MAXN], deg[MAXN];
vector<int> gr[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(dp,0);
	ms(deg,0);

	int N,M; cin>>N>>M;
	for (int i=0; i<M; i++) {
		int a, b; cin>>a>>b;
		gr[a].push_back(b);
		deg[b]++;
	}	

	stack<int> st;
	for (int i=1; i<=N; i++)
		if (deg[i]==0)
			st.push(i),
			dp[i]=0;
	while (SZ(st)) {
		int node=st.top(); st.pop();
		for (int child : gr[node]) {
			deg[child]--;
			dp[child]=max(dp[child], dp[node]+1);
			if (deg[child]==0) st.push(child);
		}
	}
	cout << (*max_element(dp+1,dp+N+1)) << endl;
}