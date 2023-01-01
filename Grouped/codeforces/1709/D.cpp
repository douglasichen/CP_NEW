#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M; cin>>N>>M;
	vector<int> T(M<<1);
	for (int i=0; i<M; i++) cin>>T[M+i];
	for (int i=M-1; i; i--) T[i]=max(T[i<<1], T[i<<1|1]);
	
	int Q; cin>>Q;
	while (Q--) {
		int y1,x1,y2,x2,K; cin>>y1>>x1>>y2>>x2>>K;
		bool A=(y2-y1)%K==0 && (x2-x1)%K==0;
		int h1=y1+(N-y1)/K*K;
		
		// search seg
		if (x1>x2) swap(x1,x2);
		x1--;
		int h2=T[x1+M];
		for (x1+=M, x2+=M; x1<x2; x1>>=1, x2>>=1) {
			if (x1&1) h2=max(h2,T[x1++]);
			if (x2&1) h2=max(h2,T[--x2]);
		}
		if (h1>h2 && A) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}