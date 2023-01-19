#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=101, MAXW=1e5+1;
ll dp[MAXN][MAXW], arW[MAXN], arV[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(dp,0);
	int N,W; cin>>N>>W;
	for (int i=1; i<=N; i++) cin>>arW[i]>>arV[i];
	for (int i=1; i<=N; i++) {
		for (int w=0; w<=W; w++) {
			dp[i][w]=max(dp[i-1][w], (arW[i]<=w ? dp[i-1][w-arW[i]]+arV[i] : 0LL));
		}
	}
	cout << (*max_element(dp[N],dp[N]+W+1)) << endl;
}