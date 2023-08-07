#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=1001;
ll N, A[MAXN], B[MAXN], dp[MAXN][MAXN];
char S[MAXN], T[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	dp[0][0]=0;

	cin>>N;
	for (int i=1; i<=N; i++) cin>>S[i];
	for (int i=1; i<=N; i++) cin>>A[i];
	for (int i=1; i<=N; i++) cin>>T[i];
	for (int i=1; i<=N; i++) cin>>B[i];
	
	for (int a=1; a<=N; a++)
		for (int b=1; b<=N; b++)
			dp[a][b]=max({dp[a][b-1], dp[a-1][b], dp[a-1][b-1] + 
				(S[a]!=T[b] && ( S[a]=='W' ? (A[a]>B[b]) : (A[a]<B[b]) ) ? A[a]+B[b] : 0)});
	cout << dp[N][N] << '\n';
}