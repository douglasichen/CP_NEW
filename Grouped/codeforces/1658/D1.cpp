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
		int L, R, ans=0; cin>>L>>R; R++;
		vector<int> V(R);
		for (int i=0; i<R; i++) cin>>V[i];
		for (int e=0; e<18; e++) {
			int cnt=0;
			for (int &i : V) cnt+=(i&1), i>>=1;
			if (cnt>R-cnt) ans+=(1<<e);
		}
		cout << ans << endl;
	}	
}