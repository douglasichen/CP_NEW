#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int TC; cin>>TC;
	while (TC--) {
		int N; cin>>N;
		vector<int> A(N), B(N);
		for (int i=0; i<N; i++) cin>>A[i]>>B[i];
		int L=0, R=N;
		while (L<R) {
			int X=L+R+1>>1, cnt=0;
			for (int i=0, at=0; i<N && cnt<X; i++)
				if (at<=B[i] && X-at-1<=A[i])
					cnt++, at++;
			if (X==cnt) L=X;
			else R=X-1;
		}
		cout << L << endl;
	}	
}