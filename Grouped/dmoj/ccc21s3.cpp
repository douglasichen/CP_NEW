#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	ll ans=LLONG_MAX;
	vector<ll> P(N), W(N), D(N);
	for (int i=0; i<N; i++) cin>>P[i]>>W[i]>>D[i];
	ll L=0, R=1e9, M1, M2, sm1, sm2;
	while (L<R) {
		M1=L+R>>1, M2=M1+1;
		sm1=0, sm2=0;
		for (int i=0; i<N; i++) {
			sm1+=max(abs(P[i]-M1)-D[i],0LL) * W[i];
			sm2+=max(abs(P[i]-M2)-D[i],0LL) * W[i];
		}
		ans=min(sm1,sm2);
		if (sm1<=sm2) R=M1;
		else L=M2;
	}
	cout << ans << endl;
}