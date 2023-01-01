#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int N,M,ans=0;
bool in(vector<int> &p) {
	return p[0]>=0 && p[0]<N && p[1]>=0 && p[1]<M;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	vector<int> left={0,M-1}, right={0,0};
	vector<vector<int>> Q, dirs={{0,1}, {1,0}, {0,-1}, {-1,0}}, egs;
	vector<vector<bool>> vis(N, vector<bool>(M)), W=vis, G=vis;
	char ch;
	for (int y=0; y<N; y++)
		for (int x=0; x<M; x++)
			cin>>ch, G[y][x]=(ch=='#');
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			if (vis[y][x] || G[y][x]) continue;
			vis[y][x]=1;
			Q.push_back({y,x});
			while (!Q.empty()) {
				vector<int> back=Q.back(); Q.pop_back();
				if (G[back[0]][back[1]]) {
					W[back[0]][back[1]]=1;
					egs.push_back(back);
					if (back[1]>=right[1]) right=back;
					if (back[1]<=left[1]) left=back;
					continue;
				}
				for (vector<int> dir : dirs) {
					vector<int> nxt={dir[0]+back[0], dir[1]+back[1]};
					if (in(nxt) && !vis[nxt[0]][nxt[1]])
						vis[nxt[0]][nxt[1]]=1,
						Q.push_back(nxt);
				}
			}

			if (left[0]==right[0] && (right[1]-left[1])%2==0 && egs.size()) {
				bool gd=1;
				int i=0, cnt=0;
				vector<int> a(2), b=a, c=a, d=a;
				while (left[1]+i<=right[1]-i) {
					a={left[0]+i, left[1]+i}, b={left[0]-i, left[1]+i}, c={right[0]+i, right[1]-i}, d={right[0]-i, right[1]-i};
					if (!(in(a) && in(b) && in(c) && in(d) && W[a[0]][a[1]] && W[b[0]][b[1]] && W[c[0]][c[1]] && W[d[0]][d[1]]))
						gd=0;
					i++;
					cnt+=4;
				}
				cnt-=4;
				if (gd && cnt==egs.size()) ans++;
			}

			left={0,M-1};
			right={0,0};
			while (!egs.empty()) {
				vector<int> back=egs.back();
				vis[back[0]][back[1]]=0;
				W[back[0]][back[1]]=0;
				egs.pop_back();
			}
		}
	}
	cout << ans << endl;
}