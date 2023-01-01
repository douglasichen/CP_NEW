#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);
	
	int N; cin>>N;
	string S; cin>>S;
	for (int k=1; k<=N; k++) {
		map<string,bool> M;
		bool gd=1;
		for (int i=0; i<=N-k; i++) {
			string s=S.substr(i,k);
			if (M[s]) gd=0;
			M[s]=1;
		}
		if (gd) {
			cout << k << endl;
			break;
		}
	}
}