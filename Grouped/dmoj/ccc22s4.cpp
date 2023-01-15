#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=1e6;
int ar[MAXN], fr[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(fr,0);

	int N,C; cin>>N>>C;
	for (int i=0; i<N; i++) cin>>ar[i], fr[ar[i]]++;
	sort(ar, ar+N);

	int b=2;
	ll cut=0, len;
	for (int a=0; a<N; a++) {
		while ((a<b ? ar[b]-ar[a] : ar[b]+C-ar[a])<=C/2) b=(b+1)%N;
		len=(a<b ? b-a : b+N-a)-1;
		cut+=len*(len-1)/2;
	}

	ll ans=1LL*N*(N-1)*(N-2)/6 - cut ;
	cout << ans << endl;


}