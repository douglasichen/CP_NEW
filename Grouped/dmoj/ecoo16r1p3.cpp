#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T=10;
	while (T--) {
		int N, at=0, ans=0; cin>>N;
		int valAt=N;
		vector<int> V(N);
		for (int i=0; i<N; i++) {
			cin>>V[i];
			if (V[i]==N) at=i;
		}
		for (int i=at; i>=0; i--) {
			if (V[i]==valAt) valAt--;
		}
		for (int val=valAt; val; val--) {
			int loc;
			for (int i=0; i<N; i++) if (V[i]==val) loc=i;
			ans+=loc;
			for (int i=loc; i; i--) swap(V[i],V[i-1]);
		}	
		cout << ans << endl;

	}	
}