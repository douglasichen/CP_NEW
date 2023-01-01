#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	unsigned long long N; cin>>N;
	while (N!=1) {
		cout << N << ' ';
		if (N&1) N=N*3+1;
		else N>>=1;
	}
	cout << 1 << '\n';
}