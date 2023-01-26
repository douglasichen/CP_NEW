#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define SZ(a) int(a.size())
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=1e5+1;
int ar[MAXN], mn[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	ll ans;
	while (T--) {
		int N,M,zero=0; cin>>N>>M;
		for (int i=0; i<N; i++) cin>>ar[i], zero+=(ar[i]==0);
		// for (int i=N; i>=0; i--) if (ar[0])

		ans=0;
		if (N==M) ans=-2;
		else if (zero>M) ans=-1;
		else if (M==0) ans=*min_element(ar,ar+N)-1;
		else {
			int take=M-zero;
			int i=0;
			for (; take && i<N; i++) {
				if (ar[i]) take--;
				ans+=ar[i];
			}
			int nxt=INT_MAX;
			for (; i<N; i++) {
				if (ar[i]) nxt=min(nxt,ar[i]);
			}
			ans+=nxt-1;
		}
		if (ans==-1) cout << "Impossible";
		else if (ans==-2) cout << "Richman";
		else {
			cout << ans;
		}
		cout<<endl;
	}
}