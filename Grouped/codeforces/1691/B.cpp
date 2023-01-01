#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T,N; cin>>T;
	bool ans;
	vector<int> V(1e5);
	for (int o=0; o<T; o++) {
		cin>>N;
		ans=1;
		for (int i=0; i<N; i++) cin>>V[i];

		int cnt=1;
		for (int i=1; i<N; i++) {
			if (V[i]==V[i-1]) cnt++;
			else {
				if (cnt==1) {
					ans=0;
					break;
				}
				cnt=1;
			}
		}
		cout << ans << endl;
	}	
}