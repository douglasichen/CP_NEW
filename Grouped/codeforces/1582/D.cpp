#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		vector<int> A(N), B(N);
		for (int &i : A) cin>>i;
		if (N&1) {
			if (A[0]+A[1]) B[0]=-A[2], B[1]=-A[2], B[2]=(A[0]+A[1]);
			else if (A[0]+A[2]) B[0]=-A[1], B[1]=(A[0]+A[2]), B[2]=-A[1];
			else B[0]=(A[1]+A[2]), B[1]=-A[0], B[2]=-A[0];
		}
		for (int i=(N&1)*3; i<N; i+=2) {
			B[i]=A[i+1];
			B[i+1]=-A[i];
		}
		for (int &i : B) cout << i << ' '; cout << endl;
	}	
}