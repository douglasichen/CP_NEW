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
		int N; cin>>N;
		int cnt=0,ans=0;
		for (int i=0,e; i<N; i++) {
			cin>>e;
			if (e) cnt++;
			else {
				if (cnt) ans++;
				cnt=0;
			}
		}
		if (cnt) ans++;
		cout << min(ans,2) << endl;
	}	
}