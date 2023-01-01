#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

<<<<<<< HEAD
	int md=10000019, md2=11000057, md3=12000959, p=31, p2=37, p3=29;
=======
	ll md=100000021909, p=29;
>>>>>>> 1432c1ee88857353d3fb117ea91e4454899448db
	string A,B; cin>>A>>B;
	for (char &c : A) c-='A'-1;
	for (char &c : B) c-='A'-1;

	int M=A.size(), N=B.size(), ans=0;

	// init P
<<<<<<< HEAD
	vector<int> P(N), P2, P3; P[0]=1, P2=P, P3=P;
	for (int i=1; i<N; i++) 
		P[i]=P[i-1]*p%md, 
		P2[i]=P2[i-1]*p2%md2,
		P3[i]=P3[i-1]*p3%md3;

	// init map
	bitset<12000959> has, has2, has3;
	int h=0, h2=0, h3=0;
	for (int i=0; i<N; i++) 
        h=(h+B[i]*P[N-i-1])%md, 
        h2=(h2+B[i]*P2[N-i-1])%md2,
		h3=(h3+B[i]*P3[N-i-1])%md3;
=======
	vector<ll> P(N); P[0]=1;
	for (int i=1; i<N; i++) P[i]=P[i-1]*p%md;

	// init map
	map<ll,bool> has;
	ll h=0, h2=0;
	for (int i=0; i<N; i++) h=(h+B[i]*P[N-i-1])%md;
>>>>>>> 1432c1ee88857353d3fb117ea91e4454899448db
	for (int i=0; i<N; i++) {
		has[h]=1;
		h=((h-B[i]*P[N-1])%md+md)%md;
		h=h*p%md;
		h=(h+B[i])%md;
<<<<<<< HEAD

		has2[h2]=1;
		h2=((h2-B[i]*P2[N-1])%md2+md2)%md2;
		h2=h2*p2%md2;
		h2=(h2+B[i])%md2;

		has3[h3]=1;
		h3=((h3-B[i]*P3[N-1])%md3+md3)%md3;
		h3=h3*p3%md3;
		h3=(h3+B[i])%md3;
	}
	h=0, h2=0, h3=0;

	if (M>=N) {
		// init A hash
		for (int i=0; i<N; i++) 
            h=(h+A[i]*P[N-i-1])%md, 
            h2=(h2+A[i]*P2[N-i-1])%md2,
			h3=(h3+A[i]*P3[N-i-1])%md3;
		if (has[h] && has2[h2] && has3[h3]) ans=1;
=======
	}
	h=0;

	if (M>=N) {
		// init A hash
		for (int i=0; i<N; i++) h=(h+A[i]*P[N-i-1])%md;
		if (has[h]) ans=1;
>>>>>>> 1432c1ee88857353d3fb117ea91e4454899448db
		for (int a=0, b=N; b<M && !ans; a++, b++) {
			h=((h-A[a]*P[N-1])%md+md)%md;
			h=h*p%md;
			h=(h+A[b])%md;
<<<<<<< HEAD
			
			h2=((h2-A[a]*P2[N-1])%md2+md2)%md2;
			h2=h2*p2%md2;
			h2=(h2+A[b])%md2;

			h3=((h3-A[a]*P3[N-1])%md3+md3)%md3;
			h3=h3*p3%md3;
			h3=(h3+A[b])%md3;

			if (has[h] && has2[h2] && has3[h3]) ans=1;
=======
			if (has[h]) ans=1;
>>>>>>> 1432c1ee88857353d3fb117ea91e4454899448db
		}
	}
	cout << (ans ? "yes" : "no") << endl;
}