#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	int V[N][2];
	for (int i=0; i<N; i++) cin>>V[i][0]>>V[i][1];
	vector<int> A(N),B(N);
	iota(A.begin(), A.end(), 0);
	B=A;

	// sort
	sort(A.begin(), A.end(), [&](int &a, int &b) {
		return V[a][0]<V[b][0];
	});
	sort(B.begin(), B.end(), [&](int &a, int &b) {
		return V[a][1]<V[b][1];
	});

	ll bSm=0, bestB, bestA, ans;
	bitset<500000> bTake;
	int aOrder=0, C=B[0];
	for (int i=0; i<N; i++) {
		while (bTake[A[aOrder]]) aOrder++;
		bestB=V[A[aOrder]][0]+bSm, bestA=V[C][0]+bSm-V[C][1]+V[B[i]][1];
		ans=min(bestB, bestA);
		cout << ans << endl;

		bTake[B[i]]=1;
		bSm+=V[B[i]][1];
		if (V[B[i]][0]-V[B[i]][1] < V[C][0]-V[C][1]) C=B[i];
	}

}