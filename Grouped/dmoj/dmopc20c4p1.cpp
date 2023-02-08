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
	ll N,S,a,b,dif;
	while (T--) {
		cin>>N>>S;
		a=1;
		b=N*(N+1)/2-S-1;
		if (b<0) cout << 0 << endl;
		else {
			if (b>N) {
				dif=b-N;
				a+=dif;
				b-=dif;
				if (a<=b) cout << (b-a+1)/2 << endl;
				else cout << 0 << endl;
			}
			else cout << (b-a+1)/2 << endl;
		}
	}
}