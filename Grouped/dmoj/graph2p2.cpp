#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=1000;
bool gr[MAXN][MAXN];
int vis[MAXN], ans=1;

int N, k=0;

void dfs(int node) {
	for (int child=0; child<N; child++) {
		if (gr[node][child]) {
			if (vis[child]==k) ans=0;
			else if (!vis[child]) vis[child]=k, dfs(child);
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(vis,0);

	cin>>N;
	for (int a=0; a<N; a++)
		for (int b=0; b<N; b++)
			cin>>gr[a][b];
	for (int a=0; a<N; a++)
		if (!vis[a])
			vis[a]=++k,
			dfs(a);
	cout << (ans ? "YES" : "NO") << endl;
}