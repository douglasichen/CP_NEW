#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
    
    int R,C,ans=0; cin>>R>>C;
    vector<vector<char>> G(R, vector<char>(C));
    vector<vector<bool>> vis(R, vector<bool>(C));
    vector<vector<int>> dirs={
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };
    for (int y=0; y<R; y++)
        for (int x=0; x<C; x++)
            cin>>G[y][x],
            vis[y][x]=(G[y][x]=='#');
    for (int y=0; y<R; y++) {
        for (int x=0; x<C; x++) {
            if (vis[y][x]) continue;
            int cnt=(G[y][x]=='M');
            queue<vector<int>> Q;
            vis[y][x]=1;
            Q.push(vector<int>{y,x});
            while (!Q.empty()) {
                vector<int> from=Q.front(); Q.pop();
                for (vector<int> dir : dirs) {
                    vector<int> nxt={dir[0]+from[0], dir[1]+from[1]};
                    if (nxt[0]>=0 && nxt[0]<R && nxt[1]>=0 && nxt[1]<C)
                        if (!vis[nxt[0]][nxt[1]] && G[nxt[0]][nxt[1]]!='#')
                            Q.push(nxt),
                            vis[nxt[0]][nxt[1]]=1,
                            cnt+=G[nxt[0]][nxt[1]]=='M';
                }
            }
            ans+=cnt>0;
        }
    }
	cout << ans << '\n';
    
}