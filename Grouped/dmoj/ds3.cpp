#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int gcd(int a, int b) {
	while (b) {
		a%=b;
		swap(a,b);
	}
	return a;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M; cin>>N>>M;
	vector<vector<int>> T(N<<1, vector<int>(3));
	for (int i=0, e; i<N; i++) cin>>e, T[i+N]={e,e,1};
	for (int i=N-1; i>0; i--) {
		int c1=i<<1, c2=i<<1|1;
		T[i]={min(T[c1][0], T[c2][0]), gcd(T[c1][1],T[c2][1]), 0}; // mn, gcd, cnt of mn
		if (T[c1][0]==T[c2][0]) T[i][2]=T[c1][2]+T[c2][2];
		else if (T[c1][0]<T[c2][0]) T[i][2]=T[c1][2];
		else T[i][2]=T[c2][2];
	}
	
	for (int i=0; i<M; i++) {
		char c; int a,b; cin>>c>>a>>b;
		if (c=='C') {
			int i=a+N-1;
			T[i][0]=T[i][1]=b;
			for (i>>=1; i; i>>=1) {
				int c1=i<<1, c2=i<<1|1;
				T[i]={min(T[c1][0], T[c2][0]), gcd(T[c1][1],T[c2][1]), 0}; // mn, gcd, cnt of mn
				if (T[c1][0]==T[c2][0]) T[i][2]=T[c1][2]+T[c2][2];
				else if (T[c1][0]<T[c2][0]) T[i][2]=T[c1][2];
				else T[i][2]=T[c2][2];
			}
			// for (int i=0; i<N*2; i++) cout << T[i][2] << ' '; cout << endl;
		}
		else {
			int L=a+N-1, R=b+N;
			int mn=T[L][0];
			for (; L<R; L>>=1, R>>=1) {
				if (L&1) mn=min(mn, T[L][0]), L++;
				if (R&1) mn=min(mn, T[R-1][0]), R--;
			}
			if (c=='M') cout << mn << endl;
			else {
				L=a+N-1, R=b+N;
				int g=T[L][1];
				for (; L<R; L>>=1, R>>=1) {
					if (L&1) g=gcd(g, T[L][1]), L++;
					if (R&1) g=gcd(g, T[R-1][1]), R--;
				}
				if (c=='G') cout << g << endl;
				else {
					if (g==mn) {
						L=a+N-1, R=b+N;
						int f=0;
						for (; L<R; L>>=1, R>>=1) {
							if (L&1) {
								if (T[L][0]==mn) f+=T[L][2];
								L++;
							}
							if (R&1) {
								if (T[R-1][0]==mn) f+=T[R-1][2];
								R--;
							}
						}
						cout << f << endl;
					}
					else cout << 0 << endl;
				}
			}
		}
	}
}