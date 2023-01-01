#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int L,A,B,N; cin>>L>>A>>B>>N;
	vector<int> V(N+2); V[N+1]=L;
	for (int i=1; i<=N; i++) cin>>V[i];
	sort(V.begin()+1, V.begin()+N+1);
	for (int i=1; i<=N+1; i++)
		V[i]=V[i-1]+(V[i]-V[i-1])%2520;
	
	bitset<1000000> rock;
	for (int i=1; i<=N; i++) rock[V[i]]=1;

	int INF=101;
	vector<int> dp(V.back()+1, INF); dp[0]=0;
	for (int i=0; i<=V.back(); i++) {
		for (int at=max(i-B,0); at<=i-A; at++) {
			dp[i]=min(dp[at]+rock[i], dp[i]);
		}
	}
	int ans=INF;
	for (int i=V.back(); i>=(max(0,V.back()-B)); i--) {
		ans=min(ans,dp[i]);
	}
	// for (int i : dp) cout << i << ' '; cout << endl;
	cout << ans << endl;
}