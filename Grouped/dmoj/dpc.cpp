#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=1e5+1;
int ar[MAXN][3], dp[MAXN][3];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	for (int a=1; a<=N; a++)
		for (int b=0; b<3; b++)
			cin>>ar[a][b];
	
	for (int i=1; i<=N; i++) {
		for (int a=0; a<3; a++) {
			for (int b=0; b<3; b++) {
				if (a!=b) {
					dp[i][b]=max(dp[i][b], dp[i-1][a]+ar[i][b]);
				}
			}
		}
	}
	cout << max({dp[N][0], dp[N][1], dp[N][2]}) << endl;

}