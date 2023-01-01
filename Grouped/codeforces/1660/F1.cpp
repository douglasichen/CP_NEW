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
		int N, ans=0; cin>>N;
		string S; cin>>S;
		for (int i=0; i<N; i++) {
			int A=0, B=0, C=0;
			for (int j=i; j<N; j++) {
				A+=S[j]=='+';
				B+=S[j]=='-';
				C+=j>i && S[j]=='-' && S[j-1]=='-';
				if (A<=B && (B-A)%3==0 && (B-A)/3<=C) ans++;//, cout << i << ' ' << j << endl;
			}
		}
		cout << ans << endl;
	}	
}