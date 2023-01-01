#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T,N;

void F(vector<int> &V) {
	int at=0;
	for (int i=0; i<N; i++) if (V[i]) V[at]=V[i], at++;
	N=at;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>T;
	while (T--) {
		cin>>N;
		vector<int> V(++N);
		V[0]++;
		for (int i=0,p; i<N-2; i++) cin>>p, V[p]++;
		sort(V.begin(), V.end());

		F(V);
		int t=N;
		for (int i=0; i<N; i++) V[i]=max(V[i]-i-1, 0);
		F(V);

		while (N) {
			int mxI=0;
			for (int i=0; i<N; i++) {
				if (V[i]) V[i]--;
				if (V[mxI]<V[i]) mxI=i;
			}
			if (V[mxI]) V[mxI]--;
			t++;
			F(V);
		}
		cout << t << endl;
	}	
}