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
		vector<int> V(N);
		for (int i=0; i<N; i++) cin>>V[i];
		sort(V.begin(), V.end());
		cout << V[N-1]+V[N-2]-V[0]-V[1] << endl;
	}
}