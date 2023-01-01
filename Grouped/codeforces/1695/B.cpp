#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin>>T;
	for (int o=0; o<T; o++) {
		int N; cin>>N;
		vector<int> V(N+1);
		for (int i=1; i<=N; i++) cin>>V[i];
		if (N%2) cout << "Mike" << endl;
		else {
			int a=1e9, b=1e9;
			for (int i=1; i<=N; i+=2) a=min(a,V[i]);
			for (int i=2; i<=N; i+=2) b=min(b,V[i]);
			if (a<b) cout << "Joe" << endl;
			else if (b<a) cout << "Mike" << endl;
			else {
				int ra=0, rb=0;
				for (int i=1; i<=N; i+=2) {
					if (V[i]==a) {
						ra=i;
						break;
					}
				}
				for (int i=2; i<=N; i+=2) {
					if (V[i]==b) {
						rb=i;
						break;
					}
				}
				if (ra<rb) cout << "Joe" << endl;
				else cout << "Mike" << endl;
			}
		}
	}
}