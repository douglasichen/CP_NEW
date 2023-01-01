#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'

// vector<int> D={0,4, 2, 1, 3}, Q={0,1,2,3,4};

int que(int i) {
	cout << "? " << i << endl; cout.flush();
	cin>>i;
	return i;

	// vector<int> V=Q;
	// for (int i=1; i<Q.size(); i++) Q[i]=V[D[i]];

	// cout << "? " << i << endl;
	// cout << "got: " << V[i] << endl;
	// return V[i];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin>>T;
	while (T--) {
		int N, cnt=0; cin>>N;
		vector<int> P(N+1);
		for (int i=1; i<=N && cnt<N-1; i++) {
			if (P[i]) continue;
			
			int a=0, b=0, pre;
			a=que(i);
			pre=a;
			while (b!=a && cnt<N-1) {
				b=que(i);
				if (P[pre]==0) cnt++;
				P[pre]=b;
				pre=b;
			}
		}
		int sm=0;
		for (int &e : P) sm+=e;
		for (int i=1; i<=N; i++) if (P[i]==0) P[i]=N*(N+1)/2-sm;
		cout << "!";
		for (int i=1; i<=N; i++) cout << ' ' << P[i]; cout << endl; cout.flush();
	}
}