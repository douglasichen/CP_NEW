#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N, one=0, ans=1; cin>>N;
		vector<int> V(N);
		for (int i=0; i<N; i++) cin>>V[i];
		for (int &i : V) one+=i==1;
		for (int i=0; i<N; i++) if (V[(i+1)%N]-V[i]>1) ans=0;
		cout << (ans&(one==1) ? "YES" : "NO") << endl;
	}	
}