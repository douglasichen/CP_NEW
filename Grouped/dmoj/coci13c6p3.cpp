#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int N;

long long q(int &h, vector<int> &V) {
	int mid=N>>1;
	long long res=0;
	for (int i=0; i<N; i++) {
		int need=abs(i-mid)+h;
		res+=abs(need-V[i]);
	}
	return res;
}

long long solve(vector<int> &A, vector<int> &B) {
	long long ans=0, x=0, y=0;
	int L=1, R=1<<30;
	while (L<R) {
		int a=L+R>>1, b=a+1;
		x=q(a,A)+q(a,B), y=q(b,A)+q(b,B);
		if (x<y) R=a;
		if (y<=x) L=b;
	}
	return q(L,A)+q(R,B);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	vector<int> A(N),B(N);
	for (int &i : A) cin>>i;
	for (int &i : B) cin>>i;
	cout << solve(A,B) << endl;	
}