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
		int A,B,C=1e9; cin>>A>>B;
		int ans=B-A;
		bitset<20> aV, bV;
		bV=B;
		for (int i=A; i<B; i++) {
			aV=i;
			int b=0;
			for (int at=19; at>=0; at--) {
				if (bV[at]) b+=1<<at;
				else if (aV[at]) {
					b+=1<<at;
					break;
				}
			}
			ans=min(ans,i+(i|b)+1-A-B);
			aV.reset();
		}
		cout << ans << endl;
	}	
}