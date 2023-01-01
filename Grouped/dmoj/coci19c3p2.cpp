#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S; cin>>S;
	int N=S.size(), Q; cin>>Q;
	vector<vector<int>> T('z'+1, vector<int>(2*N));
	for (int i=0; i<N; i++) T[S[i]][i+N]++;
	for (char c='a'; c<='z'; c++) {
		for (int i=N-1; i>0; i--) T[c][i]=T[c][i<<1]+T[c][(i<<1)+1];
	}
	vector<vector<int>> R(Q,vector<int>(2));
	for (int i=0; i<Q; i++) cin>>R[i][0]>>R[i][1], R[i][0]--, R[i][1]--;

	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i], V[i]--;

	int at=0;
	for (int i=0; i<N; i++) {	
		int p=V[i];
		bool gd=1;
		while (at<Q && gd) {
			for (char c='a'; c<='z'; c++) {
				int cnt=0;
				int A=R[at][0], B=R[at][1]; B++;
				for (A+=N, B+=N; A<B; A>>=1, B>>=1) {
					if (A&1) cnt+=T[c][A++];
					if (B&1) cnt+=T[c][--B];
				}
				if (cnt>1) {
					gd=0;
					break;
				}
			}
			if (gd) at++;
		}
		if (at==Q) {
			cout << i << endl;
			break;
		}

		
		// modify tree
		char c=S[p];
		int e=p;
		for (T[c][e+=N]--; e>0; e>>=1) T[c][e>>1]--;
	}
}