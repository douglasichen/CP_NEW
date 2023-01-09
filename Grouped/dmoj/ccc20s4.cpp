#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int MAXN=1e6+1;
int psa[3][MAXN], N;

int sm(int a, int l, int r) {
	if (l<=N && r>N) return psa[a][r-N]+(psa[a][N]-psa[a][l]);
	if (l>N) l-=N, r-=N;
	return psa[a][r]-psa[a][l];
}

int solve(int a, int b, int c) {
	int A=psa[a][N], B=psa[b][N], C=psa[c][N], ans=1e6;
	for (int i=0; i<N; i++) {
		ans=min(ans, sm(b,i,i+A) + sm(c,i,i+A) + sm(c,i+A,i+A+B) + max(0,sm(c,i,i+A) - sm(a,i+A+B,i+A+B+C)));
	}
	return ans;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(psa,0);

	string S; cin>>S;
	N=SZ(S);
	for (int i=0; i<N; i++) {
		for (int o=0; o<3; o++) psa[o][i+1]=psa[o][i];
		if (S[i]=='A') psa[0][i+1]++;
		if (S[i]=='B') psa[1][i+1]++;
		if (S[i]=='C') psa[2][i+1]++;
	}

	int ans=1e6;
	for (int a=0; a<3; a++) {
		for (int b=0; b<3; b++) {
			for (int c=0; c<3; c++) {
				if (a!=b && b!=c && a!=c) {
					ans=min(ans,solve(a,b,c));
				}
			}
		}
	}
	cout << ans << endl;
}