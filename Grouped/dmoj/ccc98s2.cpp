#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i=1000; i<=9999; i++) {
		int at=i, sm=0; at--;
		while (--at)
			if (i%at==0)
				sm+=at;
		if (sm==i)
			cout << i << ' ';
	}
	cout << endl;

	long long sm=0, a;
	for (int i=100; i<=999; i++) {
		string at=to_string(i);
		sm=0;
		for (char c : at) {
			a=c-'0';
			sm+=a*a*a;
		}
		if (sm==i) cout << i << ' ';
	}
	cout << endl;
}