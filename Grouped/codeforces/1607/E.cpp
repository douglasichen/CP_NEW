#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	map<char,vector<int>> Q;
	Q['L']={0,-1};
	Q['R']={0,1};
	Q['U']={-1,0};
	Q['D']={1,0};
	int T; cin>>T;
	while (T--) {
		int N,M; cin>>N>>M;
		string S; cin>>S;
		int L=0, R=S.size();
		vector<int> ans={1,1};
		while (L<R) {
			int X=L+R+1>>1, x1=0, x2=0, y1=0, y2=0;
			vector<int> pos={0,0};
			for (int i=0; i<X; i++) {
				pos={pos[0]+Q[S[i]][0], pos[1]+Q[S[i]][1]};
				y1=min(y1,pos[0]), y2=max(y2, pos[0]), x1=min(x1,pos[1]), x2=max(x2,pos[1]);
			}
			int x=x2-x1+1, y=y2-y1+1;
			if (y<=N && x<=M) L=X, ans={-y1+1,-x1+1};
			else R=X-1;
		}
		cout << ans[0] << ' ' << ans[1] << endl;
	}	
}