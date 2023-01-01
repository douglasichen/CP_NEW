#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;

	vector<long long> T(2*N);
	vector<vector<int>> A(N,vector<int>(2));
	for (int i=0; i<N; i++) cin>>A[i][0], A[i][1]=i;
	sort(A.begin(), A.end());

	int Q; cin>>Q;
	vector<vector<int>> V(Q,vector<int>(4));
	for (int i=0; i<Q; i++) cin>>V[i][1]>>V[i][2]>>V[i][0], V[i][3]=i;
	sort(V.begin(),V.end());

	vector<long long> ans(Q);
	
	int at=N-1;
	for (int i=Q-1; i>=0; i--) {
		vector<int> v=V[i];
		while (at>=0 && A[at][0]>=v[0]) {
			// modify seg tree
			int p=A[at][1];
			for (T[p+=N]=A[at][0]; p>0; p>>=1) T[p>>1]=T[p]+T[p^1];
			at--;
		}
		int a=v[1], b=v[2]+1;
		long long sm=0;
		for (a+=N, b+=N; a<b; a>>=1, b>>=1) {
			if (a&1) sm+=T[a++];
			if (b&1) sm+=T[--b];
		}

		ans[v[3]]=sm;
	}

	for (long long i : ans) cout << i << endl;
}