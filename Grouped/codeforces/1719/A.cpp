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
		int N,M; cin>>N>>M;
		bool ans=0;
		if (M&1) ans=N&1;
		else ans=!(N&1);
		cout << (ans ? "Tonya" : "Burenka") << endl;
	}
}