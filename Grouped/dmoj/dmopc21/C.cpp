#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	ll N,S,T; cin>>N>>S>>T;
	ll val=powl(2,30)-1;
	vector<char> O(N+1);
	vector<ll> V(N+1); V[0]=S;
	for (int i=1; i<=N; i++) {
		char c; ll e; cin>>c>>e;
		if (c=='A') e&=V[i-1];
		else if (c=='O') e|=V[i-1];
		else e^=V[i-1];
		V[i]=e;
		O[i]=c;
	}

	
	
	int ans=-1;
	if (V.back()==T) ans=0;
	else {
		int k=N, cnt=0;
		for (int i=N; i>=0; i--) {
			k=i;
			if (O[i]!='A') break;
			cnt+=(V[i]!=val);
		}
		if (k>0) ans=cnt+(V[k]!=val);
	}
	
	cout << ans << endl;
}