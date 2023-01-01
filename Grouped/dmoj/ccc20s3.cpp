#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

bool eq(vector<int> &A, vector<int> &B) {
	for (int i=0; i<A.size(); i++)
		if (A[i]!=B[i])
			return 0;
	return 1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll md=100000015187, p=31;
	string A,B; cin>>A>>B;
	for (char &c : A) c-='a'-1;
	for (char &c : B) c-='a'-1;

	int N=A.size(), H=B.size();
	vector<ll> P(N); P[0]=1;
	for (int i=1; i<N; i++)
		P[i]=P[i-1]*p%md;

	int ans=0;
	map<ll,bool> M;
	if (N<=H) {
		vector<int> F1(27), F2(27);
		ll h=0;
		for (int i=0; i<N; i++) h=(h+B[i]*P[N-i-1])%md, F1[A[i]]++, F2[B[i]]++;
		if (eq(F1,F2)) M[h]=1, ans++;
		for (int a=0, b=N; b<H; a++, b++) {
			F2[B[a]]--, F2[B[b]]++;
			h=((h-B[a]*P[N-1])%md+md)%md;
			h=h*p%md;
			h=h+B[b]%md;
			if (eq(F1,F2) && !M[h]) ans++, M[h]=1;
		}
	}
	cout << ans << endl;
}