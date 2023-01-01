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
		string S; cin>>S;
		int N=S.size();
		vector<int> ones;
		for (int i=0; i<N; i++) if (S[i]-'0') ones.push_back(i);

		int O=ones.size(), L=0, R=O;
		while (L<R) {
			int mid=L+R>>1, sz=N;
			for (int i=0; i<O; i++) {
				int j=i+O-mid-1;
				if (j>=O) break;
				sz=min(sz, ones[j]-ones[i]+1);
			}
			bool gd=sz-(O-mid)<=mid;
			if (gd) R=mid;
			else L=mid+1;
		}
		cout << R << endl;

	}
}