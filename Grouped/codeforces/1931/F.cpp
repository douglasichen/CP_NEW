#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=2e5+1;
int to[MAXN], ar[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		ms(to,0);
		int N,K; cin>>N>>K;
		bool ans=1;
		for (int a=0; a<K; a++) {
			for (int i=0; i<N; i++) cin>>ar[i];
			if (a==0) {
				for (int i=1; i<N-1; i++) {
					to[ar[i]]=ar[i+1];
				}
			}
			else {
				int cnt=0;
				for (int i=1; i<N-1; i++) {
					if (i<N-2 && ar[i+2]==to[ar[i]]) cnt++;
					else if (i<N-2 && to[ar[i+1]]==ar[i+1]) cnt++;
					else if (to[ar[i]]!=ar[i+1]) ans=0;
				}
				if (cnt>1) ans=0;
				cout << cnt << ' ' << ans << endl;
			}
		}
		cout << (ans ? "YES" : "NO") << endl;

	}	
}