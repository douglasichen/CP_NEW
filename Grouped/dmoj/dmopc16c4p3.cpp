#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<vector<int>> T(101, vector<int>(2e5+2)); // first index is N+1, store answer in index N
vector<int> D(1e5+1);
int N,S,Q;

void upt(int a, int b, int val) {
	for (T[a][b+=N]=val, b>>=1; b; b>>=1)
		T[a][b]=D[T[a][b<<1]] < D[T[a][b<<1|1]] ? T[a][b<<1] : T[a][b<<1|1];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>S;
	D[0]=INT_MAX;
	for (int i=1; i<=N; i++) cin>>D[i];
	for (int i=0,a,b; i<S; i++)
		cin>>a>>b,
		upt(b,a,a);
	
	cin>>Q;
	while (Q--) {
		char ch;
		int a,b; cin>>ch>>a;
		if (ch=='Q') {
			int L=1, R=N+1, ans=0;
			for (L+=N, R+=N; L<R; L>>=1, R>>=1) {
				if (L&1) {
					if (D[T[a][L]]<D[ans]) ans=T[a][L];
					L++;
				}
				if (R&1) {
					R--;
					if (D[T[a][R]]<D[ans]) ans=T[a][R];
				}
			}
			cout << (ans ? ans : -1) << endl;
		}
		else {
			cin>>b;
			if (ch=='A') upt(b,a,a);
			else if (ch=='S') upt(b,a,0);
			else {
				D[a]=b;
				for (int i=0; i<=100; i++) upt(i,a,0);
			}
		}
	}

	
}