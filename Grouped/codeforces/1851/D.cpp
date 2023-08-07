#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=2e5;
ll ar[MAXN]={0};
int f[MAXN+1];
bool has[MAXN+1];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		for (int i=1; i<N; i++) cin>>ar[i];
		ms(has,0);

		ll dif=0, k=0;
		int cnt=0;
		
		ms(f,0);
		bool ans=1;
		for (int i=1; i<N; i++) {
			dif=ar[i]-ar[i-1];
			if (dif<=N) {
				has[dif]=1, f[dif]++;
				if (f[dif]>1) ans=0;
			}
			else k=dif, cnt++;
			
		}
		if (cnt>1) ans=0;
		for (int i=1; cnt && i<=N; i++) if (!has[i]) k-=i;
		if (k!=0) ans=0;

		cout << (ans ? "YES" : "NO") << endl;
	}	
}