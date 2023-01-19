#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=11, INF=1e9;
int X[MAXN], Y[MAXN];
int N,M,K;

pair<bool,int> dfs(int x, int y, int c) {
	if (y<=0) return {0,INF};
	if (x==M+1) return {1,c};

	pair<bool,int> res={0,INF}, tmp={0,0};
	for (int a=y+X[x]; a<=N; a+=X[x]) {
		tmp=dfs(x+1,a,c+1);
		if (tmp.first && tmp.second<res.second) res=tmp;
	}
	
	tmp=dfs(x+1,y-Y[y],c);
	if (tmp.first && tmp.second<res.second) res=tmp;
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M>>K;
	for (int i=1; i<=N; i++) cin>>X[i]>>Y[i];

	pair<bool,int> ans={0,0};
	for (int y=1; !ans.first && y<=N; y++) {
		ans=dfs(1,y,0);
	}
	cout << ans.first << endl;
	if (ans.first) cout << ans.second << endl;
	else cout << 0 << endl;

}