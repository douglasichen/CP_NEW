#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<int> V;
long long scr, N, M;

void change(int i, int val) {
	if (V[i]==val) return;
	long long o=i*(N-i-1);
	if (i) {
		if (val==V[i-1]) scr-=i+o;
		else if (V[i]==V[i-1]) scr+=i+o;
	}
	if (i<N-1) {
		if (val==V[i+1]) scr-=N-i-1+o;
		else if (V[i]==V[i+1]) scr+=N-i-1+o;
	}

	V[i]=val;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	V.assign(N,0);
	scr=N*(N+1)/2;
	for (int i=0, val; i<N; i++) cin>>val, change(i,val);
	while (M--) {
		int i, val; cin>>i>>val;
		change(i-1,val);
		cout << scr << endl;
	}
}