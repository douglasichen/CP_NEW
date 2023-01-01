#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

long long gcd(long long a, long long b) {
	while (b) {
		a%=b;
		swap(a,b);
	}
	return a;
}

long long lcm(long long a, long long b) {
	return a*b/gcd(a,b);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q; cin>>N>>Q;
	vector<long long> V(N),B(N);
	for (int i=0; i<N; i++) cin>>V[i],B[i]=V[i];
	for (int i=1; i<N; i++) {
		B[i]=lcm(B[i-1],B[i]);
		if (B[i]>1e9) {
			for (int o=i+1; o<N; o++) B[o]=1e9+1;
			break;
		}
	}
	for (int i=0; i<Q; i++) {
		long long t; cin>>t;
		int l=0, r=N;
		while (l<r) {
			int mid=(l+r)>>1;
			if (t%B[mid]!=0) r=mid;
			else l=mid+1;
		}
		int ans=l+1;
		if (ans==N+1) ans=-1;
		cout << ans << endl;
	}
}