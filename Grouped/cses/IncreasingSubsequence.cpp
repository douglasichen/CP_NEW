#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	const int INF=1e9+1;
	int N; cin>>N;
	vector<int> D(N+1, INF); D[0]=-INF;
	for (int i=1,a; i<=N; i++) {
		cin>>a;
		int l=lower_bound(D.begin(), D.end(), a)-D.begin()-1;
		if (a>D[l] && a<D[l+1]) D[l+1]=a;
	}
	for (int i=N; i; i--) {
		if (D[i]<INF) {
			cout << i << endl;
			break;
		}
	}
}