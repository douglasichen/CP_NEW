#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q; cin>>N>>Q;
	vector<long long> T(N<<1);
	for (int i=0; i<N; i++) cin>>T[i+N];
	for (int i=N-1; i>0; i--) T[i]=T[i<<1]&T[i<<1|1];
	for (int i=0; i<Q; i++) {
		char ch; cin>>ch;
		if (ch=='U') {
			long long p, val; cin>>p>>val;
			p+=N-1;
			T[p]=val;
			for (p>>=1; p; p>>=1) T[p]=T[p<<1]&T[p<<1|1];
		}
		else {
			long long a,b,val; cin>>a>>b>>val;
			for (a+=N-1, b+=N; a<b; a>>=1, b>>=1) {
				if (a&1) val&=T[a], a++;
				if (b&1) val&=T[b-1], b--;
			}
			cout << val << endl;
		}
	}
}