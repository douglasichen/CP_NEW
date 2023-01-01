#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	bitset<200000> A,B;
	while (T--) {
		int N; cin>>N;
		char c;
		for (int i=0; i<N; i++) cin>>c, A[i]=c-'0';
		for (int i=0; i<N; i++) cin>>c, B[i]=c-'0';
		
		vector<int> cnt(N);
		if (A[0]!=B[0]) A.flip(), cnt[N-1]++;
		bool gd=1;
		for (int i=0; i<N; i++) if (A[i]!=B[i]) gd=0;
		if (gd) {
			for (int i=1; i<N; i++)
				if (A[i])
					cnt[i]++,
					cnt[i-1]++;
			vector<vector<int>> ans;
			if (A[0]) cnt[N-1]++, ans.push_back({2,N});
			for (int i=0; i<N; i++)
				if (cnt[i]&1)
					ans.push_back({1,i+1});
			cout << "YES" << '\n' << ans.size() << '\n';
			for (vector<int> &a : ans) cout << a[0] << ' ' << a[1] << '\n';
		}
		else cout << "NO" << endl;
	}	
}