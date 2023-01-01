#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

ll A,B,X,dif;
bool solve(ll a, ll b) {
	cout << a << ' ' << b << endl;
	if (a==X || b==X) return 1;
	if (a==0 || b==0) return 0;
	dif=abs(a-b);
	return (dif!=a ? solve(dif,b) : 0) || (dif!=b ? solve(a,dif) : 0);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		cin>>A>>B>>X;
		cout << (solve(A,B) ? "YES" : "NO") << endl;
	}
}