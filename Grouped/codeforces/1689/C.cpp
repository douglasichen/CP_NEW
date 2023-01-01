#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int TE; cin>>TE;
    while (TE--) {
        int N; cin>>N;
        vector<vector<int>> T(N+1);
        for (int i=0,a,b; i<N-1; i++) cin>>a>>b, T[a].push_back(b), T[b].push_back(a);
		if (T[1].size()<=1) {
			cout << max(0, N-2) << endl;
			continue;
		}
		

		queue<int> Q;
		vector<bool> vis(N+1); vis[1]=1;
		vector<int> cnt(N+1);
		int mn=INT_MAX;
		for (int i : T[1]) vis[i]=1, Q.push(i), cnt[i]=2+T[i].size()-1+T[1].size()-1;
		while (!Q.empty()) {
			int node=Q.front(); Q.pop();
			if (T[node].size()-1<=1) {
				mn=min(mn, cnt[node]);
				continue;
			}
			for (int i : T[node]) {
				if (!vis[i]) vis[i]=1, cnt[i]=cnt[node]+T[i].size()-1, Q.push(i);
			}
		}
		int ans=N-mn;
		cout << ans << endl;
	}
}