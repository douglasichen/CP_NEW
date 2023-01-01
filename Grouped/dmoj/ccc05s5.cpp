#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> V(N), O(N), M(N);
	for (int i=0; i<N; i++) cin>>V[i];
	auto srt=[&](int a, int b) {
		return V[a]<V[b];
	};
	iota(O.begin(), O.end(), 0);
	sort(O.begin(), O.end(), srt);
	for (int i=0; i<N; i++)
		M[O[i]]=(i ? V[O[i]]==V[O[i-1]] ? M[O[i-1]] : i : i);
	double ans=0;
	vector<int> T(N<<1);
	for (int i=0; i<N; i++) {
		// update pos
		int pos=M[i];
		T[pos+=N]++;
		for (pos>>=1; pos; pos>>=1) T[pos]=T[pos<<1]+T[pos<<1|1];
		// for (int o=0; o<N*2; o++) cout << T[o] << ' ';cout << endl;

		// sum (pos,N)
		pos=M[i];
		int L=pos+1, R=N, sm=0;
		for (L+=N, R+=N; L<R; L>>=1, R>>=1) {
			if (L&1) sm+=T[L++];
			if (R&1) sm+=T[--R];
		}
		ans+=sm+1;
	}
	// cout << ans << endl;
	cout << fixed << setprecision(2) << ans/N << endl;
}