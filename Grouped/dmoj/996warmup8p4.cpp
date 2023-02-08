#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SZ(a) int(a.size())
#define endl '\n'
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=26;
int ar[MAXN], deg[MAXN][MAXN], mxLen[MAXN][MAXN];
vector<int> dp[MAXN][MAXN]; //I,K,L


void printDp() {
	
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin>>T;
	while (T--) {
		
		ms(deg,0);
		ms(mxLen,0);

		int N,K; cin>>N>>K;
		for (int i=1; i<=N; i++) cin>>ar[i];
		
		vector<int> finAns;
		ll L=-1e9, R=1e9;
		while (L<R) {
			ll X=L+R>>1;
			// can you add to at most X
			for (int i=0; i<MAXN; i++)
				for (int k=0; k<=MAXN; k++)
					dp[i][k].clear();
			
			dp[0][0].push_back(0);
			for (int k=1; k<=K; k++) {
				for (int i=1; i<=N; i++) {
					ll sm=0;
					for (int len=1; len<=i; len++) {
						sm+=ar[i-len+1];
						if (SZ(dp[i-len][k-1]) && sm<=X) 
							dp[i][k].push_back(len), deg[i-len][k-1]++;
					}
				}
			}
			// for (int i=0; i<N; i++) {
			// 	for (int k=0; k<K; k++) {
			// 		cout << SZ(dp[i][k]) << ' ';
			// 	}
			// 	cout << endl;
			// }
			// cout << endl;

			queue<vector<int>> qu;
			qu.push({N,K});
			while (SZ(qu)) {
				vector<int> node=qu.front(); qu.pop();
				int i=node[0], k=node[1];
				if (i==0) continue;
				for (int len : dp[i][k]) {
					deg[i-len][k-1]--;
					mxLen[i-len][k-1]=max(mxLen[i-len][k-1], len);
					if (deg[i-len][k-1]==0) {
						qu.push({i-len, k-1});
					}
				}
			}

			vector<int> ans;
			if (mxLen[0][0]) {
				vector<int> at={0,0};
				while (at[0]<N) {
					ans.push_back(mxLen[at[0]][at[1]]);
					at={at[0]+mxLen[at[0]][at[1]], at[1]+1};
				}

				finAns=ans;
				R=X;
			}
			else L=X+1;
		}
		for (int i : finAns) cout << i << ' '; cout << endl;
	}

}