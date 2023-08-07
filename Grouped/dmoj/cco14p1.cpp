#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=2000;
char ar[MAXN][MAXN];
ll dp[MAXN][MAXN];
int N;

ll mxSz(int y, int x) {
	if (y>=N || x<0 || x>=N || ar[y][x]=='.') return 0;
	if (dp[y][x]) return dp[y][x];
	return dp[y][x]=min({mxSz(y+1, x-1), mxSz(y+1, x), mxSz(y+1, x+1)})+1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(dp,0);

	cin>>N;
	for (int y=0; y<N; y++)
		for (int x=0; x<N; x++)
			cin>>ar[y][x];	
	
	ll ans=0;
	for (int y=0; y<N; y++)
		for (int x=0; x<N; x++)
			ans+=mxSz(y,x);
	cout << ans << endl;
}