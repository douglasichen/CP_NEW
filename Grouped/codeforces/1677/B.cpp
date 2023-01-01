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
		int N,M; cin>>N>>M;
		int NM=N*M;
		vector<int> V(NM);
		char c;
		for (int i=0; i<NM; i++) cin>>c, V[i]=c-'0';
		vector<bool> C(M);
		vector<int> ans(NM);
		for (int i=0; i<NM; i++) {
			ans[i]=(i ? ans[i-1] : 0);
			if (V[i] && !C[i%M]) {
				C[i%M]=1;
				ans[i]++;
			}
		}
		vector<int> R(NM);
		for (int i=0, j=-1; i<NM; i++) {
			R[i]=(i-M>=0 ? R[i-M] : 0);
			if (V[i]) j=i;
			if (j>=0 && i-j<M) R[i]++;
		}
		for (int i=0; i<NM; i++) ans[i]+=R[i];
		for (int i : ans) cout << i << ' '; cout << endl;
	}
}	