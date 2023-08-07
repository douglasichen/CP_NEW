#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while(T--) {
		int N,M,K,H, ans=0; cin>>N>>M>>K>>H;
		for (int i=0,h; i<N; i++) cin>>h, ans+=((h-H)%K==0 && abs((h-H)/K)<M && h!=H);
		cout << ans << '\n';
	}	
}
