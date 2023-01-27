#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=5000;
int ar[MAXN], dp[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	for (int i=0; i<N; i++) cin>>ar[i];	
	for (int i=0; i<N; i++) {
		dp[i]=1;
		for (int o=0; o<i; o++) {
			if (ar[o]<ar[i]) dp[i]=max(dp[i], dp[o]+1);
		}
	}
	cout << *max_element(dp,dp+N) << endl;
	
}