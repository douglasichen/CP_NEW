#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	for (int t=0; t<T; t++) {
		int N, ans=1; cin>>N;
		long long sm=0;
		vector<long long> V(N), dp(N);
		for (int i=0; i<N; i++) cin>>V[i], sm+=V[i];
		if (sm!=0) ans=0;

		dp[0]=V[0];
		for (int i=1; i<N; i++) dp[i]=V[i]+dp[i-1];
		bool z=0;
		for (long long i : dp) {
			if (z && i) ans=0;
			if (i<0) ans=0;
			if (i==0) z=1;
		}
		cout << (ans ? "YES" : "NO") << endl;
	}	
}