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
		int N,K; cin>>N>>K;
		vector<int> V(N), B;
		for (int i=0; i<N; i++) cin>>V[i];
		B=V;
		for (int i=0; i<N; i++) B[i]-=N-i-1;

		auto srt=[&](int &a, int &b) {return B[a]>B[b];};
		vector<int> O(N);
		for (int i=0; i<N; i++) O[i]=i;
		sort(O.begin(), O.end(), srt);
		
		long long ans=0;
		for (int i : V) ans+=i;
		for (int i=0; i<K; i++) {
			ans+=N-O[i]-1;
			ans-=V[O[i]]+i;
		}
		cout << ans << endl;


		
	}
}