#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while (T--) {
        int N; cin>>N;
        string S; cin>>S;
		vector<int> F('z'+1);
		int cnt=0;
		for (char c : S) F[c]++, cnt+=F[c]==1;
		
		vector<char> alph(26);
		vector<char> rep(26);
		iota(alph.begin(), alph.end(), 'a');
		for (int a=0, b=0; a<N && b<N; a++) {
			char c=S[a];
			if (!rep[c]) {
				if (c==alph[b]) swap(alph[b], alph[b+1]);
				rep[c]=alph[b];
				b++;
			}
		}
		for (char &c : S) c=rep[c];
		cout << S << endl;
    }
}
