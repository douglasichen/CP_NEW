#include <bits/stdc++.h>
using namespace std;

const int MAXN=1000000, H=__builtin_clz(MAXN);
int T[MAXN<<1], D[MAXN], N, Q;

void apply(int pos, int val) {
	T[pos]+=val;
	if (pos<N) D[pos]+=val;
}

void up(int pos) {
	for (pos>>=1; pos; pos>>=1) T[pos]=max(T[pos<<1], T[pos<<1|1])+D[pos];
}
void down(int pos) {
	for (int h=H; h; h--) {
		int at=pos>>h;
		apply(at<<1, D[at]);
		apply(at<<1|1, D[at]);
		D[at]=0;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	for (int i=0; i<N; i++) cin>>T[i+N];
	for (int i=N-1; i; i--) T[i]=max(T[i<<1], T[i<<1|1]);
	cin>>Q;
	while (Q--) {
		int X,L,R; cin>>X>>L>>R;
		L+=N-1, R+=N;
		if (X==1) {
			// increment range 
			int L0=L, R0=R, C; cin>>C;
			for (; L<R; L>>=1, R>>=1) {
				if (L&1) apply(L++, C);
				if (R&1) apply(--R, C);
			}
			up(L0), up(R0-1);
		}
		else {
			// query max of range 
			down(L), down(R-1);
			int ans=INT_MIN;
			for (; L<R; L>>=1, R>>=1) {
				if (L&1) ans=max(T[L++], ans);
				if (R&1) ans=max(T[--R], ans);
			}
			cout << ans << endl;
		}
	}
}