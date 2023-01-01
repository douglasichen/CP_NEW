#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int R,C; 
vector<vector<int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
vector<vector<bool>> G;
int bfs(vector<int> &A, vector<vector<int>> X) {
    vector<vector<bool>> B(R, vector<bool>(C));
    for (vector<int> &v : X) B[v[0]][v[1]]=1;

    vector<vector<bool>> vis(R, vector<bool>(C));
    queue<vector<int>> Q; //y,x,d
    Q.push({A[0],A[1],0});
    vis[A[0]][A[1]]=1;
    while (!Q.empty()) {
        vector<int> front=Q.front(); Q.pop();
        if (B[front[0]][front[1]])
            return front[2];
        for (vector<int> &dir : dirs) {
            vector<int> nxt={dir[0]+front[0], dir[1]+front[1]};
            if (nxt[0]>=0 && nxt[0]<R && nxt[1]>=0 && nxt[1]<C)
                if (!vis[nxt[0]][nxt[1]] && !G[nxt[0]][nxt[1]])
                    vis[nxt[0]][nxt[1]]=1,
                    Q.push({nxt[0],nxt[1],front[2]+1});
        }
    }
    return 0;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin>>R>>C;
    G.assign(R, vector<bool>(C));
    vector<int> start(2), dest(2);
    cin>>start[0]>>start[1]>>dest[0]>>dest[1];
    char c;
    for (int y=0; y<R; y++)
        for (int x=0; x<C; x++)
            cin>>c, G[y][x]=(c=='X');
    int T; cin>>T;
    vector<vector<int>> B(T, vector<int>(2)), D={dest};
    for (vector<int> &v : B) cin>>v[0]>>v[1];
    cout << bfs(start, D)-bfs(start,B) << endl;
}
