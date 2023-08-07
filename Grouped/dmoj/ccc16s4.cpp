#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=401;
bool vis[MAXN][MAXN], dp[MAXN][MAXN];
int psa[MAXN], ans=0;

int sum(int l, int r) {
	if (r<l) return 0;
	return psa[r]-psa[l-1];
}

bool can(int l, int r) {
	if (r-l<=0) return 1;
	if (vis[l][r]) return dp[l][r];
	vis[l][r]=1;

	for (int a=l, b=r; a<=b; a++) {
		while (a<b && sum(b,r)<sum(l,a)) b--;
		if (a<=b && sum(l,a)==sum(b,r) && can(l,a) && can(b,r) && can(a+1,b-1)) 
			return dp[l][r]=1;
	}
	return dp[l][r]=0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(vis,0);
	ms(dp,0);
	ms(psa,0);

	// check if an interval is combinable... yes: sum, no: 0
	int N; cin>>N;
	for (int i=1,a; i<=N; i++) cin>>a, psa[i]=psa[i-1]+a;
	for (int a=1; a<=N; a++)
		for (int b=a; b<=N; b++)
			if (can(a,b))
				ans=max(ans, sum(a,b));
	
	cout << ans << endl;
}