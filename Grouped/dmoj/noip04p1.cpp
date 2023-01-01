#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int sm=0;
	int mom=0;
	for (int i=0; i<12; i++) {
		int b; cin>>b;
		sm+=300;
		sm-=b;
		int take=sm-sm%100;
		sm%=100;
		mom+=take;
		if (sm<0) {
			cout << -(i+1) << endl;
			return 0;
		}
	}
	cout << mom*1.2+sm << endl;
	// cout << sm << endl;
}

