#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	char c;
	int T; cin>>T;
	while (T--) {
		int N, cnt=0; cin>>N;
		vector<vector<int>> V(N, vector<int>(N));
		for (int y=0; y<N; y++) for (int x=0; x<N; x++) cin>>c, V[y][x]=c=='1', cnt+=V[y][x];
		
		int mxSm=0;
		for (int i=0; i<N; i++) {
			int sm=0;
			for (int j=0; j<N; j++) {
				int y=i+j, x=j;
				y%=N, x%=N;
				sm+=V[y][x];
			}
			mxSm=max(sm,mxSm);
		}
		cout << (N-mxSm)+(cnt-mxSm) << endl;
	}	
}