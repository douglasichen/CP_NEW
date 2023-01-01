#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T,md=998244353; cin>>T;
	while (T--) {
		int N,M,K,Q,cnt=0,x,y; cin>>N>>M>>K>>Q;
		vector<long long> ans(Q+1); ans[0]=1;
		for (int i=1; i<=Q; i++) ans[i]=ans[i-1]*K%md;

		vector<vector<int>> vQ(Q, vector<int>(2));
		for (int i=0; i<Q; i++) cin>>vQ[i][0]>>vQ[i][1];

		unordered_map<int,bool> row, col;
		for (int i=Q-1; i>=0; i--) {
			int y=vQ[i][0], x=vQ[i][1];
			if (!row[y] && col.size()!=M || !col[x] && row.size()!=N) row[y]=1, col[x]=1, cnt++;
		}
		cout << ans[cnt] << endl;
	}	
}