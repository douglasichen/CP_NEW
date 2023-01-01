#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	vector<vector<char>> G(N, vector<char>(M));
	vector<int> start;
	vector<vector<int>> cams, dirs={{1,0}, {0,1}, {-1,0}, {0,-1}}, emps;
	for (int y=0; y<N; y++)	{
		for (int x=0; x<M; x++) {
			cin>>G[y][x];
			if (G[y][x]=='S') start=vector<int>{y,x};
			else if (G[y][x]=='C') cams.push_back(vector<int>{y,x});
			else if (G[y][x]=='.') emps.push_back(vector<int>{y,x});
		}
	}
	for (vector<int> &cam : cams) {
		for (vector<int> &dir : dirs) {
			for (int i=1; ; i++) {
				vector<int> pos={cam[0]+dir[0]*i, cam[1]+dir[1]*i};
				if (G[pos[0]][pos[1]]=='W') break;
				if (G[pos[0]][pos[1]]=='.' || G[pos[0]][pos[1]]=='S') G[pos[0]][pos[1]]='X';
			}
		}
	}

	unordered_map<char, vector<int>> conv;
	conv['U']={-1,0};
	conv['D']={1,0};
	conv['R']={0,1};
	conv['L']={0,-1};

	vector<vector<int>> vis(N, vector<int>(M)), hitVis=vis, D(N, vector<int>(M, -1));
	queue<vector<int>> Q;
	Q.push(start), vis[start[0]][start[1]]=1, D[start[0]][start[1]]=0;
	while (!Q.empty() && G[start[0]][start[1]]=='S') {
		vector<int> node=Q.front(); Q.pop();
		for (vector<int> &dir : dirs) {
			vector<int> pos={node[0]+dir[0], node[1]+dir[1]};
			if (pos[0]>=0 && pos[0]<N && pos[1]>=0 && pos[1]<M && !vis[pos[0]][pos[1]])
				if (G[pos[0]][pos[1]]=='.') {
					vis[pos[0]][pos[1]]=1,
					Q.push(pos),
					D[pos[0]][pos[1]]=D[node[0]][node[1]]+1;
				}
				else if (conv[G[pos[0]][pos[1]]].size()) {
					vector<int> at=pos;
					stack<vector<int>> hit;
					while (conv[G[pos[0]][pos[1]]].size() && !hitVis[pos[0]][pos[1]] && !vis[pos[0]][pos[1]]) {
						hit.push(pos);
						hitVis[pos[0]][pos[1]]=1;
						vector<int> dir=conv[G[pos[0]][pos[1]]];
						pos={pos[0]+dir[0], pos[1]+dir[1]};
					}
					bool loop=hitVis[pos[0]][pos[1]];
					while (!hit.empty()) {
						vector<int> at=hit.top(); hit.pop();
						hitVis[at[0]][at[1]]=0;
						if (loop) vis[at[0]][at[1]]=1;
					}

					if (!vis[pos[0]][pos[1]] && G[pos[0]][pos[1]]=='.')
						vis[pos[0]][pos[1]]=1,
						Q.push(pos),
						D[pos[0]][pos[1]]=D[node[0]][node[1]]+1;
				}
		}
	}

	for (vector<int> &emp : emps) cout << D[emp[0]][emp[1]] << endl;
}