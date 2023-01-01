#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,E; cin>>N>>E;
	vector<int> V(N+1);
	for (int i=1; i<=N; i++) cin>>V[i];
	sort(V.begin()+1, V.end(), greater<int>());
	int L=1, R=N, h=0;
	while (L<R) {
		int M=L+R+1>>1,e=E;
		bool gd=1;
		for (int i=1; i<=M; i++) {
			if (M-V[i]>=2) gd=0;
			else if (M-V[i]==1) {
				if (e) e--;
				else gd=0;
			}
		}
		if (gd) L=M;
		else R=M-1;
	}
	cout << L << endl;
}