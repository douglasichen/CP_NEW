#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const ll INF=4e18;
ll N, Q, T[200000]={INF}, D[100000]={0}, S[100000]={0}, H, ans;

void applyIncr(int P, int val) {
	T[P]+=val;
	if (P<N) D[P]+=val;
}

void build(int P) {
	for (P>>=1; P; P>>=1) T[P]=min(T[P<<1], T[P<<1|1])+D[P];
}

void pushIncr(int P) {
	for (int h=H; h; h--) {
		int i=P>>h;
		applyIncr(T[i<<1], D[i]);
		applyIncr(T[i<<1|1], D[i]);
		D[i]=0;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>Q;
	H=__builtin_clz(N);
	for (int i=0; i<N; i++) cin>>T[i+N];
	for (int i=N-1; i; i--) T[i]=min(T[i<<1], T[i<<1|1]);
	while (Q--) {
		int X, L, R; cin>>X>>L>>R;
		L+=N-1, R+=N+1;
		if (X==3) {
			// output answer by:
			// push delayed operations down while setting them to 0 (they were used)
			// query result + output

			pushIncr(L), pushIncr(R-1);
			ans=INF;
			for (; L<R; L>>=1, R>>=1) {
				if (L&1) ans=min(ans, T[L++]);
				if (R&1) ans=min(ans, T[--R]);
			}
			cout << ans << endl;
		}
		else {
			int val; cin>>val;
			if (X==1) {
				// increment
				int L0=L, R0=R;
				for (; L<R; L>>=1, R>>=1) {
					if (L&1) applyIncr(L++, val);
					if (R&1) applyIncr(--R, val);
				}
				build(L0), build(R0-1);
			}
		}
	}
}
