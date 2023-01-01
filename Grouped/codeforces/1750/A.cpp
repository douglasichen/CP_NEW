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
		for (int &i : V) cin>>i;
		cout << (V[0]==1 ? "YES" : "NO") << endl;
	}	
}