#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int E=31, MAXN=101, INF=1e9;
int dp[E][MAXN][MAXN], ones[E][MAXN], zeros[E][MAXN], ar[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(dp,0);
	for (int e=1; e<E; e++)
		for (int a=1; a<MAXN; a++)
			for (int b=a+1; b<MAXN; b++)
				dp[e][a][b]=INF;

	ms(ones,0);
	ms(zeros,0);

	int N; cin>>N;
	for (int i=1; i<=N; i++) {
		int a; cin>>a; ar[i]=a;
		for (int e=1; e<E; e++) {
			if (a>>()&1) ones[e][i]++;
			else zeros[e][i]++;
		}
	}
	for (int e=1; e<E; e++) {
		for (int i=1; i<=N; i++) {
			ones[e][i]+=ones[e][i-1];
			zeros[e][i]+=zeros[e][i-1];
		}
	}

	for (int e=1; e<E; e++) {
		for (int a=1; a<=N; a++) {
			for (int b=a+1; b<=N; b++) {
				for (int i=0; i<=b-a+1; i++) {
					dp[e][a][b]=min(dp[e][a][b], 
						ones[e][a+i-1]-ones[e][a-1] + zeros[e][b]-zeros[e][a+i-1] +
						dp[e-1][a][a+i-1] + dp[e-1][a+i][b]);
				}
			}
		}
	}
	
	// for (int i=1; i<=N; i++) {
	// 	cout << ar[i] << ": \t";
	// 	for (int e=5; e>=0; e--) {
	// 		cout << (ar[i]>>e&1) << ' ';
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	// for (int a=1; a<=N; a++) {
	// 	for (int b=a+1; b<=N; b++) {
	// 		cout << a << "," << b << ":\t";
	// 		for (int e=25; e<E; e++) {
	// 			cout << dp[e][a][b] << ' ';
	// 		}
	// 		cout << endl;
	// 	}
	// }
	cout << dp[E-1][1][N] << endl;

}

