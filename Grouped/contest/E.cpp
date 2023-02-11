#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SZ(a) int(a.size())
#define ms(a,b) memset(a,b,sizeof(a))
#define endl '\n'

const int MAXN=5001;
int ar[MAXN], dp[MAXN][MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(dp,0);
	ms(ar,0);

	int N,K; cin>>N>>K;
	for (int i=1; i<=N; i++) cin>>ar[i];
	sort(ar+1,ar+N+1);
	
	for (int k=1; k<=K; k++) {
		int x=1;
		for (int i=1; i<=N; i++) {
			while (ar[i]-ar[x]>5) x++;
			dp[i][k]=max(dp[i-1][k], dp[x-1][k-1]+(i-x+1));
		}
	}
	cout << *max_element(dp[N],dp[N]+MAXN) << endl;
}