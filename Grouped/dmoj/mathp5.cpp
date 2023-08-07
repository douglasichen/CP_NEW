#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MD=1e9+7, MAXN=1e6+1;
ll fac[MAXN];

ll fpw(int a, int b) {
	ll x=a, ans=1;
	while (b) {
		if (b&1) {
			ans=ans*x%MD;
		}
		b>>=1;
		x=x*x%MD;
	}
	return ans;
}

ll choose(int a, int b) {
	return fac[a]*fpw(fac[b]*fac[a-b]%MD, MD-2)%MD;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	fac[0]=1;
	int N; cin>>N;
	
	for (int i=1; i<=N; i++) fac[i]=fac[i-1]*i%MD;

	ll ans=0;
	for (int i=1; i<=N; i++) {
		int len=N-i+1, k=i;
		if (len-k+1>=k) {
			ans=(ans+choose(len-k+1,k))%MD;
		}
	}
	cout << ans << endl;
}
