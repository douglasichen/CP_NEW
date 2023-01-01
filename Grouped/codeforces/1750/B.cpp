#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	long long x,y,a,b,p,q;
	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		x=0,y=0,a=0,b=0, p=0,q=0;
		for (int i=0; i<N; i++) {
			char c; cin>>c;
			if (c=='0') x++, y=0, a++;
			else x=0, y++, b++;
			p=max(p,x), q=max(q,y);
		}
		cout << max({p*p,q*q,a*b}) << endl;
	}	
}