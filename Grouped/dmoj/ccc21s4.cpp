#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int INF=1e9;
void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,W,D; cin>>N>>W>>D;
	vector<vector<int>> wG(N+1);
	for (int w=0,a,b; w<W; w++) 
		cin>>a>>b,
		wG[b].push_back(a);
	vector<int> P(N+1), T(N+1);
	for (int i=1; i<=N; i++) cin>>P[i];
	for (int i=1; i<=N; i++) T[P[i]]=i-1;
	
	vector<int> dis(N+1, INF);
	vector<bool> vis(N+1);
	queue<int> Q;
	Q.push(N);
	vis[N]=1;
	dis[N]=0;
	while (!Q.empty()) {
		int node=Q.front(); Q.pop();
		for (int &w : wG[node])
			if (!vis[w])
				Q.push(w),
				dis[w]=dis[node]+1, 
				vis[w]=1;
	}

	vector<vector<int>> H(N+1<<1, vector<int>(2)); // station, dis
	for (int i=1; i<=N; i++)
		H[i+N]={i, dis[i]+T[i]};
	for (int i=N; i; i--) {
		int a=i<<1, b=i<<1|1;
		if (H[a][1]<H[b][1]) H[i]=H[a];
		else H[i]=H[b];
	}
	
	for (int d=1,x,y; d<=D; d++) {
		cin>>x>>y;
		swap(P[x], P[y]);
		int dX=x-1-T[P[x]], dY=y-1-T[P[y]];
		T[P[x]]=x-1;
		T[P[y]]=y-1;


		H[P[x]+N][1]+=dX;
		H[P[y]+N][1]+=dY;
		for (int i : {P[x]+N, P[y]+N}) {
			for (i>>=1; i; i>>=1) {
				int a=i<<1, b=i<<1|1;
				if (H[a][1]<H[b][1]) H[i]=H[a];
				else H[i]=H[b];
			}
		}

		vector<int> ans={0,INF};
		int L=1, R=N+1;
		for (L+=N, R+=N; L<R; L>>=1, R>>=1) {
			if (L&1) {
				if (H[L][1]<ans[1]) ans=H[L];
				L++;
			}
			if (R&1) {
				R--;
				if (H[R][1]<ans[1]) ans=H[R];
			}
		}
		cout << ans[1] << endl;
	}
}