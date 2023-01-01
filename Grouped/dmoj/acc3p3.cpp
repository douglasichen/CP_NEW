#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<string> V(N);
	vector<vector<int>> F(N, vector<int>('z'+1));
	for (int i=0; i<N; i++) {
		cin>>V[i];
		for (char c : V[i]) F[i][c]++;
	}
	vector<int> M('z'+1, 1e9);
	for (char c='a'; c<='z'; c++) for (int i=0; i<N; i++) M[c]=min(M[c], F[i][c]);

	string ans="";
	vector<int> ats(N);
	for (char c='z'; c>='a'; c--) {
		if (!M[c]) continue;
		for (int i=0; i<N; i++) {
			int cnt=M[c];
			for (int o=ats[i]; cnt && o<V[i].size(); o++) {
				F[i][V[i][o]]--;
				if (V[i][o]==c) cnt--;
				else M[V[i][o]]=min(M[V[i][o]], F[i][V[i][o]]);
				ats[i]++;
			}
		}
		for (int i=0; i<M[c]; i++) ans+=c;
		M[c]=0;
	}
	if (ans.size()==0) cout << -1 << endl;
	else cout << ans << endl;
	

}