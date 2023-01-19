#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

struct Node {
	ll x=0, y=0;
};

const int TSZ=1<<20;
ll ar[TSZ], dp[TSZ];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	ms(ar,0);
	ms(dp,0);

	int N,K; cin>>N>>K;
	for (int i=1; i<=N; i++) cin>>ar[i];
	
	for (int i=1; i<=N; i++) {
		int L=max(0,i-K), R=(i-1)/K*K;
		ll mx=0;
		for (int a=i; a>R; a--) mx=max(mx, ar[a]);
		for (int a=R; a>=L; a--) {
			dp[i]=max(dp[i], dp[a]+mx);
			mx=max(mx,ar[a]);
		}
	}

	// for (int i=1; i<=N; i++) cout << dp[i] << ' '; cout << endl;
	cout << dp[N] << endl;
}

/*
7 4
6 4 8 9 3 2 4 
*/