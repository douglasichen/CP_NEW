#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int md=1e9+7;
ll fpw(ll a, ll b) {
	if (a==0 && b==0) return 1;
	ll exp=a, res=1;
	while (b) {
		if (b&1) res=res*exp%md;
		exp=exp*exp%md;
		b>>=1;
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int a,b,c; cin>>a>>b>>c;
		cout << fpw(a,fpw(b,c)) << endl;
	}
}

int main() {
	int N;
	vector<string> A(N), B(N);
	for (int i=0; i<N; i++) cin>>A[i];
	for (int i=0; i<N; i++) cin>>B[i];
	int a=0, b=0;
	for (int i=0; i<N; i++) {
		if (A[i]=="rock") {
			if (B[i]=="paper") b++;
			else if (B[i]=="scissors") a++;
		}
		else if (A[i]=="paper") {
			if (B[i]=="scissors") b++;
			else if (B[i]=="rock") a++;
		}
		else {
			if (B[i]=="rock") b++;
			else if (B[i]=="paper") a++;
		}
	}
	cout << a << ' ' << b << endl;
}