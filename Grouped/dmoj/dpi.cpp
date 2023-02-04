#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=3000;
double dp[MAXN][MAXN], ar[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	for (int i=1; i<=N; i++) cin>>ar[i];
	dp[0][0]=1;
	for (int i=1; i<=N; i++) {
		for (int x=1; x<=N; x++) {
			dp[i][x]=dp[i-1][x-1]*ar[i];
		}
	}
	for (int i=0; i<=N; i++) {
		for (int x=0; x<=N; x++) {
			cout << dp[i][x] << '\t';
		}
		cout << endl;
	}
	double ans=0;
	// for (int x=N/2+1; x<=N; x++) {
	// 	for (int i=0; i<=N; i++)
	// }
	cout << ans << endl;
}