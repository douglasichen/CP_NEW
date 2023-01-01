#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N,K; cin>>N>>K;
		string S; cin>>S;
		int last=N;
		char best='a';
		for (int i=0; i<N; i++) {
			if (S[i]-'a'>K) {
				last=i;
				break;
			}
			best=max(best,S[i]);
		}
		int left=(K-(best-'a'));
		vector<char> D;
		for (char c=best; c>'a'; c--) D.push_back(c);
		if (last<N) for (int i=0; i<left; i++) D.push_back(S[last]-i);
		for (char c : D) {
			for (int i=0; i<N; i++) if (S[i]==c) S[i]=(S[i]=='a' ? 'z' : S[i]-1);
		}
		cout << S << endl;
	}	
}