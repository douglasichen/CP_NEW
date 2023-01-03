#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T,N; cin>>T>>N;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];
	sort(V.begin(), V.end());

	// bsearch to find position of first element >=X;
	while (T--) {
		int X; cin>>X;
		int L=0, R=N;
		while (L<R) {
			int mid=(L+R)/2;
			if (V[mid]<X) L=mid+1;
			else R=mid;
		}
		cout << "index: " << R << endl;
	}
}