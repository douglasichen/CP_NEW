#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define SZ(a) int(a.size())
#define endl '\n'
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=101, INF=1e9;
int dp[MAXN][MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int y=0; y<MAXN; y++)
		for (int x=0; x<MAXN; x++)
			dp[y][x]=INF;
	dp[1][0]=0;

	int N,V; cin>>N>>V;
	int X=100;
	for (int i=2; i<=N; i++) {
		for (int v=0; v<V; v++) {
			for (int x=0; x<=X; x++) {
				int fuel=v+1-x;
				if (fuel<=V && fuel>=0) {
					dp[i][v]=min(dp[i][v], dp[i-1][fuel]+x*(i-1));
				}
			}
		}
	}

	cout << *min_element(dp[N], dp[N]+MAXN) << endl;
}