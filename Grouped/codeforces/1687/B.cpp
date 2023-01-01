#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	vector<int> L(M), O(M);
	string S(M,'0');
	for (int i=0; i<M; i++) {
		S[i]='1';
		cout << "? " << S << endl; cout.flush();
		cin>>L[i];
		O[i]=i;
		S[i]='0';
	}
	auto srt=[&](int &a, int &b) {return L[a]<L[b];};
	sort(O.begin(), O.end(), srt);
	int ans=0;
	for (int i=0, e; i<M; i++) {
		S[O[i]]='1';
		cout << "? " << S << endl;
		cin>>e;
		if (e==ans+L[O[i]]) ans+=L[O[i]];
		else S[O[i]]='0';
	}
	cout << "! " << ans << endl; cout.flush();
}