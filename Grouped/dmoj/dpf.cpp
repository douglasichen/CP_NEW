#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

vector<int> dp[3001][3001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(dp,0);
	for (int a=0; a<=3000; a++) {
		for (int b=0; b<=3000; b++) {
			dp[a][b]={0,0,0};
		}
	}

	string A,B; cin>>A>>B;
	A=char(0)+A;
	B=char(0)+B;
	
	for (int a=1; a<SZ(A); a++) {
		for (int b=1; b<SZ(B); b++) {
			int x=dp[a-1][b-1][0]+(A[a]==B[b]), y=dp[a-1][b][0], z=dp[a][b-1][0];
			if (x>=max(y,z)) {
				dp[a][b][1]=a-1;
				dp[a][b][2]=b-1;
			}
			else if (y>=max(x,z)) {
				dp[a][b][1]=a-1;
				dp[a][b][2]=b;
			}
			else {
				dp[a][b][1]=a;
				dp[a][b][2]=b-1;
			}
			dp[a][b][0]=max({x,y,z});
			// for (int i=0; i<3; i++) cout << dp[a][b][i] << ',';
			// cout << ' ';
		}
		// cout << endl;
	}

	string ans="";
	vector<int> at={dp[SZ(A)-1][SZ(B)-1][0], SZ(A)-1, SZ(B)-1};
	while (at[0]) {
		vector<int> go=dp[at[1]][at[2]], go2=dp[go[1]][go[2]];
		if (go[0]!=go2[0]) ans+=A[at[1]];//, cout << at[0] << ":" << at[1] << endl;
		at=go;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	
}