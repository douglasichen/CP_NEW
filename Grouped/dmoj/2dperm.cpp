#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M,Q,a,b; cin>>N>>M>>Q;
	vector<int> ans(N*M+1);
	for (int y=1; y<=N; y++) 
		for (int x=1; x<=M; x++)
			a=y*x, b=N*M-(N-y+1)*(M-x+1)+1,
			ans[a]++, ans[b+1]--;
	for (int i=1; i<=N*M; i++) ans[i]+=ans[i-1];
			
	while (Q--) {
		int q; cin>>q;
		cout << ans[q] << endl;
	}
}