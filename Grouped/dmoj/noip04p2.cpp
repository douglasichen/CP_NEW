#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	multiset<int> M;
	for (int i=0; i<N; i++) {
		int a; cin>>a;
		M.insert(a);
	}
	int ans=0;
	while (M.size()>1) {
		int a=*M.begin();
		M.erase(M.begin());
		int b=*M.begin();
		M.erase(M.begin());
		ans+=a+b;
		M.insert(a+b);
	}
	cout << ans << endl;
}

