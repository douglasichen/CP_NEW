#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=1e4+1;
vector<int> A[MAXN], B[MAXN];
bool valid[MAXN], con[MAXN], vis[MAXN];
int dis[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	for (int i=0; i<M; i++) {
		int a,b; cin>>a>>b;
		A[a].push_back(b);
		B[b].push_back(a);
	}

	// B is is the inverse to get all nodes that can get to T;
	int S,T; cin>>S>>T;

	ms(valid,0);
	ms(con,0);
	ms(vis,0);
	vis[T]=1;
	queue<int> qu; qu.push(T);
	while (SZ(qu)) {
		int node=qu.front(); qu.pop();
		con[node]=1;
		for (int child : B[node]) {
			if (!vis[child]) {
				vis[child]=1;
				qu.push(child);
			}
		}
	}

	ms(vis,0);
	for (int i=1; i<=N; i++) {
		int sm=0;
		for (int child : A[i]) sm+=con[child];
		if (sm==SZ(A[i])) valid[i]=1;
	}

	ms(vis,0);
	ms(dis,0);
	vis[S]=1;
	qu.push(S);
	int ans=-1;
	while (SZ(qu)) {
		int node=qu.front(); qu.pop();
		if (node==T) ans=dis[node];
		for (int child : A[node]) {
			if (!vis[child] && valid[child]) {
				vis[child]=1;
				dis[child]=dis[node]+1;
				qu.push(child);
			}
		}
	}
	cout << ans << endl;
}