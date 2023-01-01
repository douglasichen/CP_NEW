#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll N,T,md=998244353; cin>>N>>T;
    vector<ll> A(N), B(N);
    for (int i=0; i<N; i++) cin>>A[i]>>B[i];
    ll L=1, R=1e18;
    while (L<R) {
        ll M=L+R>>1, sum=0, took=0;
        for (int i=0; i<N; i++) {
			if (M>=A[i]) continue;
            ll a=A[i], b=B[i], r=a%b,
                K=(a-r)/b+1, p=(M<r ? 0 : (M-r)/b+1), k=K-p,
                k1=(k%2==0 ? k/2 : k), k2=((k-1)%2==0 ? (k-1)/2 : k-1),
                sm=(k1%md)*(k2%md)%md*(b%md)%md + (p%md)*(b%md)%md*(k%md)%md + (r%md)*(k%md)%md;
            sum+=sm%md;
			sum%=md;
            took+=k;
            if (took>T) break;
        }
        if (took>T) L=M+1;
        if (took<T) {
            ll need=T-took;
            sum+=(need%md)*(M%md)%md;
			sum%=md;
            for (int i=0; i<N; i++) {
                ll a=A[i], b=B[i], r=a%b;
                if (M<=a && (M-r)%b==0) need--;
            }
            if (need<=0) took=T;
            if (need>0) R=M;
        }
        if (took==T) {
            cout << sum << endl;
            return 0;
        }
    }
	ll sum=0;
	for (int i=0; i<N; i++) {
		ll a=A[i], b=B[i], r=a%b,
			k=(a-r)/b+1,
			k1=(k%2==0 ? k/2 : k), k2=((k-1)%2==0 ? (k-1)/2 : k-1),
			sm=(k1%md)*(k2%md)%md*(b%md)%md + (r%md)*(k%md)%md;
		sum+=sm%md;
		sum%=md;
	}
	cout << sum << endl;
}
