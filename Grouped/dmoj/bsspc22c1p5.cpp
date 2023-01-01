#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll unsigned long long

int md=1e9+7;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<ll> V(N);
	for (int i=0; i<N; i++) cin>>V[i];
	vector<ll> ways(61); ways[0]=1;
	for (int i=1; i<=60; i++)
		ways[i]=(ways[i-1]*ways[i-1]%md+1)%md;

	ll ans=1;
	for (int i=0; i<N; i++) {
		int e=0;
		while (e<60 && V[i]%(1ULL<<(e+1))==0) e++;
		ans=ans*ways[e]%md;
	}
	cout << ans << endl;
}