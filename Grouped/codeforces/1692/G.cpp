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
		int N,K; cin>>N>>K; K++;
		vector<bool> incr(N);
		vector<int> V(N);
		for (int i=0; i<N; i++) cin>>V[i];
		for (int i=1; i<N; i++) if ((V[i]<<1)>V[i-1]) incr[i]=1;
		
		int sm=0, cnt=0;
		for (int i=0; i<K; i++) sm+=incr[i];
		
		if (sm==K-1) cnt++;
		for (int l=0, r=K; r<N; l++, r++) {
			sm-=incr[l];
			sm+=incr[r];
			if (sm==K || sm==K-1 && !incr[l+1]) cnt++;
		}
		cout << cnt << endl;
	}
}