#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

ll gcd (ll a, ll b) {
	while (b) {
		a%=b;
		swap(a,b);
	}
	return a;
}

ll lcm(ll a, ll b) {
	return a*b/gcd(a,b);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		ll a,b,c,d; cin>>a>>b>>c>>d;
		if (a==0 && c==0) cout << 0 << endl;
		else if (a==0 || c==0) cout << 1 << endl;
		else {
			ll A=a*d, B=c*b, C=gcd(A,B);
			ll x=B/C, y=A/C;
			if (x==1) x=0;
			if (y==1) y=0;
			if (x) x=1;
			if (y) y=1;
			cout << x+y << endl;
		}
	}
}