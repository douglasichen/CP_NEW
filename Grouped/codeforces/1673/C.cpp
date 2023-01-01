#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T,N=4e4, md=1e9+7; cin>>T;
	string a,b;
	vector<int> P={0};
	for (int i=1; i<=N; i++) {
		a=to_string(i);
		b=a;
		reverse(b.begin(), b.end());
		if (a==b) P.push_back(i);
	}
	vector<vector<long long>> dp(N+1, vector<long long>(P.size()));
	for (int i=1; i<=N; i++) dp[i][1]=1;
	for (int i=1; i<P.size(); i++) dp[1][i]=1;
	for (int i=2; i<P.size(); i++) dp[P[i]][i]++;
	
	
	for (int y=2; y<=N; y++)
		for (int x=2; x<P.size(); x++)
			dp[y][x]+=dp[y][x-1]+(y-P[x]>0 ? dp[y-P[x]][x] : 0), dp[y][x]%=md;
	
	// for (int i=1; i<=13; i++) {
	// 	for (int j=1; j<=13; j++) {
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }

	while (T--) {
		cin>>N;
		cout << dp[N][P.size()-1] << '\n';
	}
}	