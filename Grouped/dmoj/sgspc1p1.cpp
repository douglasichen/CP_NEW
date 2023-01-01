#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<vector<ll>> on(31), off(31);
	for (int i=0,a; i<N; i++) {
		cin>>a;
		for (int e=0; e<31; e++, a>>=1) {
			if (a&1) on[e].push_back(i);
			else off[e].push_back(i);
		}
	}
	ll A, B;
	int X=0;
	for (int e=0; e<31; e++) {
		A=0, B=0;
		for (ll &i : on[e]) A+=(i+1)*(N-i);
		for (ll &i : off[e]) B+=(i+1)*(N-i);
		if (A>B) X+=(1<<e);
	}
	cout << X << endl;
}