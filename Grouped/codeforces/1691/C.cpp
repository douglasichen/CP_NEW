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
		vector<int> V(N);
		char c;
		for (int i=0; i<N; i++) cin>>c, V[i]=c-'0';
		if (!V[N-1]) {
			for (int i=N-2; i>=0; i--) {
				if (V[i]) {
					int dis=N-i-1;
					if (dis<=K) swap(V[i],V[N-1]), K-=dis;
					break;
				}
			}
		}
		if (!V[0]) {
			for (int i=1; i<N-1; i++) {
				if (V[i]) {
					int dis=i;
					if (dis<=K) swap(V[i],V[0]), K-=dis;
					break;
				}
			}
		}
		int ans=10*V[0]+V[N-1];
		for (int i=1; i<N-1; i++) ans+=V[i]*11;
		cout << ans << endl;
	}	
}