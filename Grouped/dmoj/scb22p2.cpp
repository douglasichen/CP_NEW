#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

ll neg(ll a, ll b) {
	if (a<0 && b<0) return b-a+1;
	if (a<0) return llabs(a);
	return 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll A,B,C,D; cin>>A>>B>>C>>D;
	if (C<=A && B<=D) cout << "burnt chicken nugget" << endl;
	else {
		ll cnt=0;
		bool has0=0;
		if (A<C && B<C || A>D && B>D) cnt=neg(A,B), has0=(A<=0 && 0<=B);
		else if (C<=A) cnt=neg(D+1,B), has0=(D<0 && 0<=B);
		else if (B<=D) cnt=neg(A,C-1), has0=(A<=0 && 0<C);
		else cnt=neg(D+1,B)+neg(A,C-1), has0=(D<0 && 0<=B) || (A<=0 && 0<C);

		if (has0) cout << 0 << endl;
		else {
			if (cnt%2==0) cout << "CHICKEN STRIP!!!" << endl;
			else cout << -1 << endl;
		}
	}
}