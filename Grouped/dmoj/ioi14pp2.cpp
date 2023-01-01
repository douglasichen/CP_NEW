#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,K; cin>>N>>K;
	vector<int> V(N+1); V[0]=1;
	for (int i=1; i<=N; i++) {
		bool b; cin>>b;
		if (b) V[i]=i;
		else V[i]=V[i-1];
	}
	int p=1,a=0;
	while (p<N) {
		int p2=min(N,p+K);
		if (V[p2]>p) p=V[p2], a++;
		else {
			a=-1;
			break;
		}
	}
	cout << a << endl;
}