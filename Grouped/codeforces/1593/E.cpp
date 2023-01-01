#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N,K; cin>>N>>K;
		vector<vector<int>> G(N+1);
		vector<int> cCnt(N+1);
		for (int i=0,a,b; i<N-1; i++) 
			cin>>a>>b,
			G[a].push_back(b),
			G[b].push_back(a),
			cCnt[a]++, cCnt[b]++;
		
		vector<int> vis(N+1);
		queue<vector<int>> Q; // node, life
		for (int i=1; i<=N; i++) {
			if (G[i].size()<=1) {
				Q.push({i,1});
				vis[i]=1;
				if (G[i].size()) cCnt[G[i][0]]--;
			}
		}
		int oLife=1;
		map<int,int> dec;
		while (!Q.empty()) {
			vector<int> q=Q.front(); Q.pop();
			int node=q[0], life=q[1];

			if (oLife<life) {
				// update cnt
				for (pair<const int,int> &i : dec) cCnt[i.first]-=i.second;
				dec.clear();
				oLife=life;
			}

			if (life<K) {
				for (int &child : G[node]) {
					if (!vis[child] && cCnt[child]<=1) {
						Q.push({child, life+1});
						vis[child]=1;
						for (int &i : G[child]) dec[i]++;
					}
				}
			}
			else break;
			
		}
		
		cout << N-accumulate(vis.begin()+1, vis.end(), 0) << endl;
	}	
}