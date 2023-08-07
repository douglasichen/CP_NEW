#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=2e5;
int ar[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N,K; cin>>N>>K;
		for (int i=0; i<N; i++) cin>>ar[i];

		pair<int,int> a={0,0}, b={0,0};
		for (int i=0; i<N; i++) {
			if (ar[i]==ar[0]) a.first++, a.second=i;
			if (a.first==K) break;
		}
		for (int i=N-1; i>=0; i--) {
			if (ar[i]==ar[N-1]) b.first++, b.second=i;
			if (b.first==K) break;
		}
		bool ans=1;
		if (ar[0]==ar[N-1]) {
			if (a.first!=K) ans=0;
		}
		else {
			if (b.second<a.second) ans=0;		
			if (a.first!=K || b.first!=K) ans=0;
		}
		cout << (ans ? "YES" : "NO") << endl;
	}	
}