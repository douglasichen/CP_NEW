#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin>>T;
	while (T--) {
		int N,K; cin>>N>>K;
		string S, ans(N,'.'); cin>>S;
		int cnt=0;
		vector<pair<int,char>> V;
		for (int i=0; i<N; i++) {
			if (S[i]=='G') {
				i+=K;
				i=min(i,N-1);
				// ans[i]='G';
				V.push_back({i,'G'});
				i+=K;
				cnt++;
			}
		}
		for (int i=0; i<N; i++) {
			if (S[i]=='H') {
				i+=K;
				i=min(i,N-1);
				// ans[i]='H';
				V.push_back({i,'H'});
				i+=K;
				cnt++;
			}
		}
		sort(V.begin(), V.end(), greater<pair<int,char>>());
		for (int i=1; i<V.size(); i++) {
			V[i].first=min(V[i].first, V[i-1].first-1);
		}
		for (pair<int,char> p : V) ans[p.first]=p.second;
		cout << cnt << endl << ans << endl;
	}
}