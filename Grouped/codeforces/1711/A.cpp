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
		int N; cin>>N;
		vector<int> ans(N);
		for (int i=1; i<=N; i++) ans[i-1]=i;
		for (int i=(N&1); i<N; i+=2) {
			swap(ans[i],ans[i+1]);
		}
		for (int i : ans) cout << i << ' '; cout << endl;
	}	
}