#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,T; cin>>N>>T;
	vector<vector<bool>> G(N,vector<bool>(N)), vis(N,vector<bool>(N));
	char c;
	for (int y=0; y<N; y++) for (int x=0; x<N; x++) cin>>c, G[y][x]=(c=='b') ? 1 : 0;
	vector<vector<int>> dirs={{0,1}, {1,0}, {0,-1}, {-1,0}};
	vector<vector<int>> D(N,vector<int>(N,2e9));
	auto srt=[](vector<int> a, vector<int> b){return a[0]>b[0];};
	priority_queue<vector<int>, vector<vector<int>>, decltype(srt)> pq(srt); // dis, y, x
	pq.emplace(vector<int>{0,0,0});
	while (!pq.empty()) {
		vector<int> top=pq.top(); pq.pop();
		if (vis[top[1]][top[2]]) continue;
		if (top[1]==N-1 && top[2]==N-1) {
			cout << top[0] << endl;
			return 0;
		}
		D[top[1]][top[2]]=min(D[top[1]][top[2]], top[0]);
		vis[top[1]][top[2]]=1;
		for (vector<int> dir : dirs) {
			vector<int> nxt={top[1]+dir[0],top[2]+dir[1]};
			if (nxt[0]>=0 && nxt[0]<N && nxt[1]>=0 && nxt[1]<N) {
				int nDis=D[top[1]][top[2]] + G[nxt[0]][nxt[1]]*T + 1;		
				
				if (nDis<D[nxt[0]][nxt[1]] && !vis[nxt[0]][nxt[1]]) {
					D[nxt[0]][nxt[1]]=min(D[nxt[0]][nxt[1]], nDis);
					pq.emplace(vector<int>{nDis, nxt[0], nxt[1]});
				}
			}
		}
	}
}