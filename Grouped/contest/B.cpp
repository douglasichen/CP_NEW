#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define SZ(a) int(a.size())
#define endl '\n'
#define ms(a,b) memset(a,b,sizeof(a))

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	ll N,S;
	// while (T--) {
	// 	cin>>N>>S;
	// 	cout << max(0LL,(N*(N+1)/2-S-1)/2) << endl;
	// }

	ll ans;
	while (T--) {
		cin>>N>>S;
		ans=0;
		for (int a=1; a<=N; a++) {
			for (int b=a+1; b<=N; b++) {
				if (N*(N+1)/2-a-b==S) ans++;
			}
		}
		cout << ans << endl;
	}
}