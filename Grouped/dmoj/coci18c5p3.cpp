#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,K; cin>>N>>K;
	vector<string> V(N);
	for (int i=0; i<N; i++) cin>>V[i];
	
	string s;
	map<string,bool> M;
	bool ans=0;
	for (int l=0; !ans && l<N-K+1; l++) {
		for (int i=0; i<N; i++) {
			s=V[i].substr(l,K);
			sort(s.begin(), s.end());
			s=V[i].substr(0,l)+s+V[i].substr(l+K,N-l-K);
			if (M[s]) {
				ans=1;
				break;
			}
			else M[s]=1;
		}
		M.clear();
	}

	cout << (ans ? "DA" : "NE") << endl;
}