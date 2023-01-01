#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<long long> rng;
	for (int i=0; i<N-1; i++) {
		long long a;
		cin>>a;
		if (i==0) rng={1LL,a-1LL};
		else rng={max(1LL,a-rng[1]), min(a-rng[0], a-1LL)};
	}
	rng[0]=max(rng[0],1LL);
	int ans=max(rng[1]-rng[0]+1LL,0LL);
	cout << ans << endl;

}