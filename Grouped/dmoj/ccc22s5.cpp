#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define SZ(a) int(a.size())
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=2001;
int cost[MAXN], on[MAXN], dp[MAXN]; 

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(cost,0);
	ms(on,0);
	ms(dp,0);

	int N; cin>>N;
	for (int i=0,a; i<N-1; i++) cin>>a>>a;

	char c;
	for (int i=1; i<=N; i++) {
		cin>>c;
		if (c=='Y') on[i]=1;
	}
	for (int i=1; i<=N; i++) {
		cin>>cost[i];
	}

	for (int i=1; i<=N; i++) {
		if (on[i]) {
			dp[i]=min(dp[i-1], dp[i-1]+cost[i] -(i-2>=0 ? cost[i-2] : 0))
		}
		else {
			dp[i]=dp[i-1]+cost[i-1];
			if (on[i-1]) {
				dp[i]=min(dp[i], dp[i-2]-onCost[i-2]+cost[i-1])
				onCost[i]=cost[i-1];
			}
		}
	}
}