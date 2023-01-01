#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		string sA,sB; cin>>sA>>sB;
		bitset<100000> A(sA), B(sB);
		int even=(A^B).count(), odd=INT_MAX;
		if (even%2 || A.count()!=B.count()) even=INT_MAX;
		if (N-A.count()+1==B.count()) odd=N-(A^B).count();

		int ans=min(even,odd);
		cout << (ans==INT_MAX ? -1 : ans) << endl;
	}
}