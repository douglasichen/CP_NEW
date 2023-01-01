#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

bool solve() {
	string A, B; cin>>A>>B;
	int at=0;
	vector<char> q;
	for (char &b : B) {
		q.push_back(b);
		while (!q.empty()) {
			char e=q.back();
			if (e==A[at]) at++, q.pop_back();
			else if (e<A[at]) return 0;
			else q.pop_back(), q.push_back(e-1), q.push_back(e-1);
		}
	}
	return at==A.size();
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) cout << (solve() ? "YES" : "NO") << endl;
}