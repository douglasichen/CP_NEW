#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N,X,mx=0; cin>>N>>X;
		vector<int> V(N+1);
		for (int i=1; i<=N; i++) cin>>V[i], mx=max(mx, V[i]);
		vector<int> A(N+1), B(N+1);
		A[0]=V[1]-1, A[N]=V[N]-1, B[0]=abs(V[1]-X), B[N]=abs(V[N]-X);
		for (int i=1; i<N; i++) A[i]=abs(V[i]-1)+abs(V[i+1]-1)-(V[i+1]-V[i]);
		for (int i=1; i<N; i++) B[i]=abs(V[i]-X)+abs(V[i+1]-X)-(V[i+1]-V[i]);
		long long ans=0;
		for (int i=1; i<N; i++) ans+=abs(V[i+1]-V[i]);
		int a=INT_MAX, b=INT_MAX;
		for (int i=0; i<=N; i++) a=min(A[i],a), b=min(B[i],b);
		ans+=a;
		if (X>mx) ans+=b;
		cout << ans << endl;
	}	
}