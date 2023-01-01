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
		int N; cin>>N;
		vector<int> H(N);
		for (int i=0; i<N; i++) cin>>H[i];
		reverse(H.begin(), H.end());
		int L=0, R=1e9+1;
		while (L<R) {
			int X=L+R+1>>1;
			bool gd=1;

			vector<int> V=H;
			for (int i=0; gd && i<N-2; i++) {
				if (V[i]>=X) {
					int d=min((V[i]-X)/3, H[i]/3);
					V[i+1]+=d;
					V[i+2]+=d*2;
				}
				else gd=0;
			}
			for (int &e : V) if (e<X) gd=0;
			if (gd) L=X;
			else R=X-1;
		}
		cout << L << endl;
	}	
}