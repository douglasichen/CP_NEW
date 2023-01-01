#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("race.in", "r", stdin);
	// freopen("race.out", "w", stdout);

	int K,N; cin>>K>>N;
	for (int i=0,X; i<N; i++) {
		cin>>X;
		int dis=0, spd=0, extra=0;
		while (dis<K) {
			spd++;
			dis+=spd;
			if (dis<K && spd>=X) dis+=spd, extra++;
		}
		cout << spd+extra << endl;
	}
}