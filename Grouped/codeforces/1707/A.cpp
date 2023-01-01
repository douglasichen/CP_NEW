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
		int N, Q; cin>>N>>Q;
		vector<int> V(N);
		for (int i=0; i<N; i++) cin>>V[i];
		int L=0, R=N;;
		pair<int, string> best={0,""};
		while (L<R) {
			int q=Q;
			string ans(N, '0');
			int mid=L+R>>1, score=0;
			bool gd=1;
			for (int i=0; i<mid; i++) if (V[i]<=Q) score++, ans[i]='1';
			for (int i=mid; i<N; i++) {
				if (V[i]<=q) score++, ans[i]='1';
				else if (q) q--, score++, ans[i]='1';
				else {
					gd=0;
					break;
				}
			}
			
			if (gd) {
				R=mid;
				if (score>=best.first) best={score, ans};
			}
			else L=mid+1;
		}
		cout << best.second << endl;
	}	
}