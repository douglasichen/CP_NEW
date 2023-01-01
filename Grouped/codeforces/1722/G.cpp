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
		int N, a=0, b=0; cin>>N;
		vector<int> V(N);
		for (int i=0; i<N-1; i++) {
			if (i&1) b^=i;
			else a^=i;
			V[i]=i;
		}
		V[N-1]=a^b;
		V[N-1]+=1<<20;
		V[N-3]+=1<<20;

		for (int i : V) cout << i << " "; cout << endl;
	}	
}