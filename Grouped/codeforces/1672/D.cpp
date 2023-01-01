#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		vector<int> A(N+1), B(N+1), F(N+1);
		for (int i=1; i<=N; i++) cin>>A[i];
		for (int i=1; i<=N; i++) cin>>B[i];
		int a=N, b=N;
		bool gd=1;
		while (a) {
			while (b && B[b]==B[b-1]) F[B[b]]++, b--;
			if (a && b && A[a]==B[b]) a--, b--;
			else if (a && F[A[a]]) F[A[a]]--, a--;
			else gd=0, a=0;
		}
		cout << (gd ? "yes" : "no") << endl;
	}	
}