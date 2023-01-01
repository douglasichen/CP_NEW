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
		string s; cin>>s;
		int N=s.size();
		vector<int> ans={1,1};
		if (s[0]=='A') {
			ans[0]=0;
		}
		bool allA=1;
		for (int i=0; i<N; i++) {
			if (s[i]=='N') {
				allA=0;
				break;
			}
		}
		if (allA) ans[1]=0;
		for (int i=1; i<N; i++) {
			if (s[i]=='N' && s[i]==s[i-1]) {
				ans={0,0};
				break;
			}
		}
		cout << ans[0] << " " << ans[1] << endl;
	}	
}