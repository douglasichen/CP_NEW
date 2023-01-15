#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=1e6;
ll ar[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,K; cin>>N>>K;
	for (int i=0; i<N; i++) cin>>ar[i];
	
	ll ans=0;
	stack<ll> a,b;
	for (int i=N-1; i>=0; i--) b.push(i==N-1 ? ar[i] : max(b.top(), ar[i]));
	for (int i=0; i<N; i++) {
		a.push(i==0 ? ar[i] : max(a.top(), ar[i])), b.pop();
		if (!SZ(a) || !SZ(b)) continue;
		if (i+1<=K && N-i-1<=K) ans=max(ans,a.top()+b.top());
	}
	if (K==N) ans=*max_element(ar,ar+N);
	cout << ans << endl;

}