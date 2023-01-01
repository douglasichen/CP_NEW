#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q; cin>>N>>Q;
	int ar[N];
	for (int i=0; i<N; i++) cin>>ar[i];
	
	ll sm,ans;
	while (Q--) {
		sm=0, ans=0;
		int X,A,B; cin>>X>>A>>B; A--;
		if (X==1) ar[A]=B;
		else {
			for (int i=A; i<B; i++) {
				sm+=ar[i];
				ans=max(ans,sm);
			}
			cout << ans << endl;
		}
	} 
}