#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	map<char,int> M;
	M['R']=0;
	M['G']=1;
	M['B']=2;

	int N; cin>>N;
	vector<int> A(N+2), B(N+2), D(N+2);
	char c;
	for (int i=1; i<=N; i++) cin>>c, A[i]=M[c];
	for (int i=1; i<=N; i++) cin>>c, B[i]=M[c];
	for (int i=1; i<=N+1; i++) D[i]=B[i]-A[i];
	for (int i=N; i; i--) D[i]=(D[i]-D[i-1]+3)%3;
	
	// 0 case
	if (A==B) {
		cout << 0 << endl;
		return 0;
	}

	// cnt=# of non 0'sa
	int cnt=0;
	for (int i=1; i<=N; i++) cnt+=(D[i]!=0);

	// queries
	int Q; cin>>Q;
	for (int q=1; q<=Q; q++) {
		int L,R; cin>>L>>R;
		if (D[L]==0) cnt++;
		if (R<N && D[R+1]==0) cnt++;

		D[L]=(D[L]-1+3)%3;
		D[R+1]=(D[R+1]+1)%3;
		
		if (!D[L]) cnt--;
		if (R<N && !D[R+1]) cnt--;

		// for (int i=1; i<=N; i++) cout << D[i] << ' '; cout << endl;
		
		if (cnt==0) {
			cout << q << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}