#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


const int INF=1e6;

int N,M;
vector<vector<int>> dirs={
	{0,1},
	{1,0},
	{-1,0},
	{0,-1}
};

vector<int> add(vector<int> &a, vector<int> &b) {
	return {a[0]+b[0], a[1]+b[1]};
}

bool in(vector<int> p) {
	return p[0]>=0 && p[0]<N && p[1]>=0 && p[1]<M;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	vector<vector<char>> G(N,vector<char>(M));
	vector<vector<int>> TD(N,vector<int>(M,INF));
	vector<vector<bool>> vis(N,vector<bool>(M));
	deque<vector<int>> tq;
	vector<int> start;
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			cin>>G[y][x];
			if (G[y][x]=='V') start={y,x}, G[y][x]='.';
			else if (G[y][x]=='+') tq.push_back({y,x}), vis[y][x]=1, TD[y][x]=0;
		}
	}
	while (!tq.empty()) {
		vector<int> back=tq.back(); tq.pop_back();
		for (vector<int> dir : dirs) {
			vector<int> nxt=add(back,dir);
			if (in(nxt)) {
				int oDis=TD[nxt[0]][nxt[1]], nDis=TD[back[0]][back[1]]+1;
				if (!vis[nxt[0]][nxt[1]] && nDis<oDis) {
					tq.push_front(nxt);
					TD[nxt[0]][nxt[1]]=nDis;
					vis[nxt[0]][nxt[1]]=1;
				}
			}
		}
	}
	vis.assign(N,vector<bool>(M));
	stack<vector<int>> s;
	vis[start[0]][start[1]]=1;
	s.push({TD[start[0]][start[1]],start[0],start[1]});
	int ans=0;
	while (!s.empty()) {
		vector<int> back=s.top(); s.pop();
		if (G[back[1]][back[2]]=='J') {
			ans=back[0];
			break;
		}

		vector<vector<int>> opt;
		for (vector<int> dir : dirs) {
			vector<int> nxt=add(back,dir);
			if (in(nxt)) {
				if (!vis[nxt[0]][nxt[1]]) {
					opt.push_back({TD[nxt[0]][nxt[1]], nxt[0], nxt[1]});
					vis[nxt[0]][nxt[1]]=1;
				}
			}
		}
		sort(opt.begin(),opt.end());
		for (vector<int> p : opt) s.push(p);
	}
	cout << ans << endl;
}