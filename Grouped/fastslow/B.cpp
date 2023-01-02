#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q; cin>>N>>Q;
	ll ar[N];
	for (int i=0; i<N; i++) cin>>ar[i];
	
	ll sm;
	while (Q--) {
		sm=0;
		int X,A,B; cin>>X>>A>>B; A--;
		if (X==3) {
			for (int i=A; i<B; i++) sm+=ar[i];
			cout << sm << endl;
		}
		else {
			int val; cin>>val;
			if (X==1) {
				for (int i=A; i<B; i++) ar[i]+=val;
			}
			else {
				for (int i=A; i<B; i++) ar[i]=val;
			}
		}
	}
}