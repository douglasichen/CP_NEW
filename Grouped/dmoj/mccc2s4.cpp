#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int f(int A, int B, int N, vector<int> &V) {
	int sz=B-A, res=0;
	for (int i=B; i<B+N-sz; i++) {
		int at=i%N, a=A+(i-B)%sz;
		res+=abs(V[at]-V[a]);
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> V(N);
	for (int &i : V) cin>>i;
	int ans=INT_MAX;
	for (int a=0; a<N; a++) {
		for (int b=a+1; b<=N; b++) {
			if (b-a==N) continue;
			if (N%(b-a)) continue;
			ans=min(ans,f(a,b,N,V));
		}
	}
	if (N==1) ans=0;
	cout << ans << endl;
}