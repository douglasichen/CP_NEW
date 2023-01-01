#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N,M;

vector<int> dsu;

int root(int a) {
	return dsu[a]<0 ? a : dsu[a]=root(dsu[a]);
}

void merge(int a, int b) {
	a=root(a), b=root(b);
	if (a==b) return;
	if (dsu[a]>dsu[b]) swap(a,b);
	dsu[a]+=dsu[b];
	dsu[b]=a;
}

int hs(vector<int> v) {
	return v[0]*M+v[1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin>>N>>M;
	dsu.assign(3000000,-1);
	vector<vector<bool>> B(N+1,vector<bool>(M+1)), vis(N+1,vector<bool>(M+1));
	vector<vector<int>> V(N+1,vector<int>(M+1)), dirs={{0,1},{1,0},{-1,0},{0,-1}};
	vector<vector<vector<int>>> P(min(N,M)+1);
	char c;
	for (int y=1; y<=N; y++) for (int x=1; x<=M; x++) cin>>c, B[y][x]=c=='X';
	for (int y=1; y<=N; y++)
		for (int x=1; x<=M; x++)
			if (!B[y][x])
				V[y][x]=min(V[y-1][x],min(V[y][x-1],V[y-1][x-1]))+1, P[V[y][x]].push_back(vector<int>{y,x});
	for (int i=min(N,M); i>0; i--) {
		for (vector<int> p : P[i]) {
			vis[p[0]][p[1]]=1;
			for (vector<int> dir : dirs) {
				vector<int> nxt={p[0]+dir[0],p[1]+dir[1]};
				if (nxt[0]>0 && nxt[0]<=N && nxt[1]>0 && nxt[1]<=M && vis[nxt[0]][nxt[1]] && !B[nxt[0]][nxt[1]])
					merge(hs(nxt),hs(p));
			}
		}
		if (P[i].size() && vis[i][i]) {
			int a=root(hs({i,i})), b=root(hs({N,M}));
			if (a==b) {
				cout << i << endl;
				return 0;
			}
		}
	}
	cout << 0 << endl;

}