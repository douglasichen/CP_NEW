#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=2e5;
int ar[MAXN], ev[MAXN], od[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while(T--) {
		int N; cin>>N;
		int a=0,b=0;
		for (int i=0; i<N; i++) {
			cin>>ar[i];
			if (ar[i]%2) od[b++]=ar[i];
			else ev[a++]=ar[i];
		}
		sort(ev,ev+a), sort(od,od+b);
		a=0, b=0;
		for (int i=0; i<N; i++) {
			if (ar[i]%2) ar[i]=od[b++];
			else ar[i]=ev[a++];
		}
		bool ans=1;
		for (int i=1; i<N; i++) {
			if (ar[i]<ar[i-1]) ans=0;
		}
		cout << (ans ? "YES" : "NO") << endl;
	}	
}