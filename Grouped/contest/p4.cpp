#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define SZ(a) int(a.size())
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=200001;
int ans=0, on[MAXN];
vector<int> tr[MAXN];

int solve(int node, int from) {
	int sm=0;
	for (int child : tr[node]) {
		if (child!=from) {
			int x=solve(child, node);
			sm+=x;
			ans=max(ans,x+on[node]);
		}
	}
	int ret=max(sm-on[node], on[node]);
	ans=max(ans,ret);
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);


	int N; cin>>N;
	for (int i=0; i<N-1; i++) {
		int a,b; cin>>a>>b;
		tr[a].push_back(b);
		tr[b].push_back(a);
	}
	char c;
	for (int i=1; i<=N; i++) {
		cin>>c;
		on[i]=(c=='1');
	}
	solve(1,1);
	cout << ans << endl;
}