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
		int N,M,ans=0; cin>>N>>M;
		vector<vector<int>> V(N, vector<int>(M));
		for (int y=0; y<N; y++) for (int x=0; x<M; x++) {
			char c; cin>>c;
			V[y][x]=(c=='1'), ans+=V[y][x];
		}
		// for (vector<int> v : V) {
		// 	for (int i : v) cout << i << ' ';
		// 	cout << endl;
		// }
		int mn=4;
		for (int y=0; y<N-1; y++) {
			for (int x=0; x<M-1; x++) {
				int sm=0;
				for (int a=y; a<y+2; a++) for (int b=x; b<x+2; b++) sm+=V[a][b];
				mn=min(mn,sm);
			}
		}
		// cout << mn << ' ';
		if (mn==3) ans--;
		else if (mn==4) ans-=2;
		cout << ans << endl;
	}
}