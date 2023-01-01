#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ull unsigned long long

ull gcd(ull a, ull b) {
	while (b) {
		a%=b;
		swap(a,b);
	}
	return a;
}

ull lcm(ull a, ull b) {
	return a*b/gcd(a,b);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		string S, pS; cin>>S; pS=S;
		vector<int> V(N);
		for (int i=0; i<N; i++) cin>>V[i], V[i]--;

		vector<ull> R(N,0);
		for (int o=0; o<N; o++) {
			vector<char> vc={S[o]};
			int at=V[o];
			while (at!=o) vc.push_back(S[at]), at=V[at];
			int sz=vc.size();
			for (int hop=1; hop<=sz; hop++) {
				if (sz%hop==0) {
					bool b=1;
					for (int i=0; i<sz; i+=hop) {
						if (vc[i]!=S[o]) {
							b=0;
							break;
						}
					}
					if (b) {
						R[o]=hop;
						break;
					}
				}
			}
		}

		ull ans=R[0];
		for (int i=1; i<N; i++) ans=lcm(ans,R[i]);
		cout << ans << endl;
	}	
}