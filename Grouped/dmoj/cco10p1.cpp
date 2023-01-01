#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int D,F,T; cin>>D;
	vector<int> W(D+1);
	for (int i=1; i<=D; i++) cin>>W[i];

	vector<vector<int>> G(D+1);
	cin>>F;
	for (int i=0,a,b; i<F; i++) {
		cin>>a>>b;
		G[a].push_back(b);
	}
	cin>>T;
	vector<int> cnt(D+1), S(D+1); S[1]=1;
	for (int t=0; t<=T; t++) {
		for (int i=1; i<=D; i++) S[i]--;
		for (int i=1; i<=D; i++) {
			if (S[i]==0) {
				for (int &child : G[i]) if (S[child]<0) S[child]=W[child];
				cnt[i]++;
			}
		}
	}

	for (int i=1; i<=D; i++) cout << cnt[i] << endl;
}