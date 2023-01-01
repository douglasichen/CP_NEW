#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

map<char,bool> A, B;

bool solve() {
	string S; cin>>S;
	int N=S.size();
	for (int i=0; i<N; i++) {
		char a=S[i];
		if (A[a]) continue;
		if (i==N-1) return 0;
		char b=S[i+1];
		if (a=='h') {
			if (!A[b] || b=='u') return 0;
		}
		else if (a!='f') {
			if (!B[a] || !A[b]) return 0;
		}
		else {
			if (b!='u') return 0;
		}
		i++;
	}
	return 1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	A['a']=1, A['i']=1, A['u']=1, A['e']=1, A['o']=1;
	B['k']=1, B['n']=1, B['h']=1, B['m']=1, B['r']=1;

	int T; cin>>T;
	while (T--) {
		cout << (solve() ? "YES" : "NO") << endl;
	}
}