#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define SZ(a) int(a.size())
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=401, INF=1e9;
vector<vector<int>> dp[2][MAXN];
bool done[MAXN][MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(done,0);

	for (int a=0; a<2; a++) {
		for (int b=0; b<MAXN; b++) {
			dp[a][b]={};
		}
	}

	int N; cin>>N;
	for (int i=0,a; i<N; i++) {
		cin>>a;
		dp[0][i].push_back({a,i+1});
		done[i][i+1]=1;
	}
	
	int change=1;
	while (change) {
		change=0;

		for (int i=0; i<N; i++) {
			// twos
			for (vector<int> a : dp[0][i]) dp[1][i].push_back(a);
			for (vector<int> a : dp[0][i]) {
				for (vector<int> b : dp[0][a[1]]) {
					if (a[0]==b[0] && !done[i][b[1]]) {
						dp[1][i].push_back({a[0]*2, b[1]});
						done[i][b[1]]=1;
						change=1;
					}
				}
			}

			for (vector<int> a : dp[0][i]) {
				for (vector<int> b : dp[0][a[1]]) {
					int at=lower_bound(dp[0][b[1]].begin(), dp[0][b[1]].end(), vector<int>{a[0],0})-dp[0][b[1]].begin();

					if (	at<SZ(dp[0][b[1]])){
						vector<int> c=dp[0][b[1]][at];

						if (a[0]==c[0] && !done[i][c[1]]) {
							dp[1][i].push_back({a[0]*2+b[0], c[1]});
							done[i][c[1]]=1;
							change=1;
						}
					}

					// for (vector<int> c : dp[0][b[1]]) {
					// 	if (a[0]==c[0] && !done[i][c[1]]) {
					// 		dp[1][i].push_back({a[0]*2+b[0], c[1]});
					// 		done[i][c[1]]=1;
					// 		change=1;
					// 	}
					// }
				}
			}
		}
		for (int o=0; o<N; o++) dp[0][o]={};
		swap(dp[0], dp[1]);
	}
	
	int ans=0;
	for (int i=0; i<N; i++) {
		for (vector<int> a : dp[0][i]) {
			ans=max(ans, a[0]);
			// cout << a[0] << ',' << a[1] << ' ';
		}
		// cout << endl;
	}
	cout << ans << endl;
}